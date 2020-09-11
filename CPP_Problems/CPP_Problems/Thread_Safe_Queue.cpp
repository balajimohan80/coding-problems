#include<thread>
#include<iostream>
#include<atomic>
#include<condition_variable>
#include<mutex>
#include<assert.h>

//Apple phone call

/*
Condition Variable(CV):
template< class Predicate >
void wait( std::unique_lock<std::mutex>& lock, Predicate pred );
Wait on the lock only when pred() returns false;
exits only when pred() returns true;
while (!pred()) {
	wait(lock);
}
*/
class thread_Safe_Queue {
public:
	thread_Safe_Queue(size_t capacity, int* mem): nCapacity(capacity-1), q_Mem(mem),
		flag(0),curr_Index(0), write_Index(0), read_Index(0) {

	}
	void push(int data) {
		std::unique_lock<std::mutex> ul(lock);
		//Locks only when Queue is fulled
		//q_Full returns true only when Q is full otherwise it reurns false
		//When q_Full retuns true, it creates a NOT operation which becomes false
		// and condition failed and lock acquired.
		cv.wait(ul, [&]() {
			return q_Full() ? false : true;
		});
		flag = 1;
#if 0
		curr_Index.fetch_add(1);
#else
		++curr_Index;
#endif
		q_Mem[write_Index] = data;
		write_Index = (write_Index + 1) % nCapacity;
		flag = 0;
		cv.notify_all();
	}

	int pop() {
		std::unique_lock<std::mutex> ul(lock);
		//Lock only when Q is empty
		//q_Empty returns true only when Q is empty, otherwise it returns false
		//q_Empty returns true, it create a NOT operation which becomes false
		// and condition failed and lock acquired.
		cv.wait(ul, [&]() {
			return q_Empty() ? false : true;
			});
		flag = 1;
#if 0
		curr_Index.fetch_sub(1);
#else
		--curr_Index;
#endif
		int val = q_Mem[read_Index];
		read_Index = (read_Index + 1) % nCapacity;
		flag = 0;
		cv.notify_all();
		return val;
	}

	bool q_Empty() {
#if 0
		return !curr_Index.load() ? true : false;
#else
		return !curr_Index ? true : false;
#endif
	}

	bool q_Full() {
#if 0
		return curr_Index.load() == nCapacity ? true : false;
#else
		return curr_Index == nCapacity ? true : false;
#endif
	}

private:
	const size_t nCapacity;
	int* q_Mem;
	std::atomic<bool> flag;
#if 0
	std::atomic<size_t> curr_Index;
#else
	size_t curr_Index;
#endif
	size_t write_Index;
	size_t read_Index;
	std::mutex lock;
	std::condition_variable cv;

};


void flush(thread_Safe_Queue& q) {
	int i = 0;
	while(1) {
		int val = q.pop();
		std::cout << val << "\n";
	}
}

void fill(thread_Safe_Queue& q) {
	int i = 0;
	while(1) {
		q.push(i++);
	}
}

int main() {
	using namespace std::chrono_literals;
	int* buffer = new int[5];
	thread_Safe_Queue q(5, buffer);
	std::thread flush_thread1(flush, std::ref(q));
	std::this_thread::sleep_for(std::chrono::milliseconds(500));
	std::thread flush_thread2(flush, std::ref(q));
	std::this_thread::sleep_for(std::chrono::milliseconds(500));
	
	std::thread fill_thread1(fill, std::ref(q));
	std::this_thread::sleep_for(std::chrono::milliseconds(500));
	std::thread fill_thread2(fill, std::ref(q));
	std::this_thread::sleep_for(std::chrono::milliseconds(500));

	flush_thread1.join();
	flush_thread2.join();
	fill_thread1.join();
	fill_thread2.join();
	delete buffer;
	return 0;
}