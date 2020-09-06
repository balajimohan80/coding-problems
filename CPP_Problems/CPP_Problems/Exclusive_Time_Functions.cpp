#include<iostream>
#include<vector>
#include<string>
#include<stack>

//frequently
//impressed
//practice again

//https://leetcode.com/problems/exclusive-time-of-functions/

/*
On a single threaded CPU, we execute some functions.  Each function has a unique id between 0 and N-1.
We store logs in timestamp order that describe when a function is entered or exited.

Each log is a string with this format: "{function_id}:{"start" | "end"}:{timestamp}".  
For example, "0:start:3" means the function with id 0 started at the beginning of timestamp 3.  
"1:end:2" means the function with id 1 ended at the end of timestamp 2.

A function's exclusive time is the number of units of time spent in this function. 
Note that this does not include any recursive calls to child functions.

The CPU is single threaded which means that only one function is being executed at a given time unit.
Return the exclusive time of each function, sorted by their function id.
*/


std::vector<int> exclusiveTime(int n, std::vector<std::string>& logs) {
	std::vector<int> res(n, 0);
	std::stack<int> st;

	size_t i = 0; 
	st.push(0);
	
	int prev = 0;
	bool is_Prev_End = 0;
	for (size_t i = 1; i < logs.size(); i++) {
		const std::string& str = logs[i];
		auto first_Delimeter_Pos  = str.find(':');
		auto second_Delimeter_Pos = str.find(':', first_Delimeter_Pos + 1);
		int function_id = std::atoi(str.substr(0, first_Delimeter_Pos).c_str());
		bool is_It_Start = str.substr(first_Delimeter_Pos + 1, second_Delimeter_Pos - first_Delimeter_Pos - 1) == "start" ? 1 : 0;
		int timeStamp = std::atoi(str.substr(second_Delimeter_Pos + 1, str.size() - second_Delimeter_Pos - 1).c_str());
		
		if (is_It_Start) {
			if (!st.empty())
			res[st.top()] += (timeStamp - prev - 1);
			st.push(function_id);
		}
		else {
			res[st.top()] += (timeStamp - prev + 1);
			st.pop();
		}
		prev = timeStamp;
	}
	return res;
}


int main() {
#if 0
	std::vector<std::string> logs = { "0:start:0","1:start:2","1:end:5","2:start:6", "2:end:8" ,"0:end:10" };
	std::vector<int> ret = exclusiveTime(3, logs);
#elif 0
	std::vector<std::string> logs = { "0:start:0", "0:start:2", "0:end:5", "0:start:6", "0:end:6", "0:end:7" };
	std::vector<int> ret = exclusiveTime(1, logs);
#else
	std::vector<std::string> logs = {"0:start:0", "0:end:0", "1:start:1", "1:end:1", "2:start:2", "2:end:2", "2:start:3", "2:end:3"};
	std::vector<int> ret = exclusiveTime(3, logs);
#endif
	for (const auto val : ret) {
		std::cout << val << " ";
	}
	std::cout << "\n";
	return 0;
}