#include<iostream>
#include<string>
#include<vector>

//To get more information about this pointer, please refer
//https://www.geeksforgeeks.org/this-pointer-in-c/



namespace BALU {

	template<typename T>
	class V_Iterator {
	public:
		using ValueType        = typename T::ValueType;
		using PointerType      = ValueType*;
		using ReferenceType       = ValueType&;
	public:
		V_Iterator(PointerType ptr): m_Ptr(ptr) {

		}

		V_Iterator& operator++() {
			m_Ptr++;
			return	*this;
		}

		V_Iterator operator++(int) {
			V_Iterator iterator = *this;
			++(*this);
			return	iterator;
		}

		V_Iterator& operator--() {
			m_Ptr--;
			return	*this;
		}

		V_Iterator operator--(int) {
			V_Iterator iterator = *this;
			--(*this);
			return	iterator;
		}

		ReferenceType operator[](size_t index) {
			return *(m_Ptr + index);
		}

		PointerType operator->() {
			return m_Ptr;
		}

		ReferenceType operator*() {
			return *m_Ptr;
		}

		bool operator==(const V_Iterator& other) const {
			return m_Ptr == other.m_Ptr;
		}

		bool operator!=(const V_Iterator& other) const {
			return !(*this == other);
		}
	private:
		PointerType m_Ptr;
#if 0
		using value_type = typename T::value_type;
		using difference_type = typename T::difference_type;
		using pointer = typename T::const_pointer;
		using reference = const value_type&;
		using _Tptr = typename T::pointer;
#endif
	
	};


	template<typename T>
	class Vector {
	public:
		using ValueType = T;
		using Iterator = V_Iterator<Vector<T>>;
	public:
		Vector(const size_t size=4):capacity_size(size), curr_Size(0), ptr(nullptr) {
			create_Memory();
		}

		Vector(const Vector& rhs):capacity_size(rhs.capacity_size),ptr(nullptr) {
			std::cout << "Copy Cons..." << "\n";
			curr_Size = rhs.curr_Size;
			ptr = new T[curr_Size];
			for (size_t i = 0; i < curr_Size; i++)
				this->ptr[i] = rhs.ptr[i];
		}

		Vector(Vector&& mv) {
			std::cout << "Move Cons..." << "\n";
			capacity_size = mv.capacity_size;
			curr_Size = mv.curr_Size;
			ptr = mv.ptr;
			mv.ptr = nullptr;
		}

		Vector& operator=(Vector&& mv) {
			std::cout << "Assignment operator..." << "\n";
			if (this != &mv) {
				capacity_size = mv.capacity_size;
				curr_Size = mv.curr_Size;
				delete []ptr;
				ptr = mv.ptr;
				mv.ptr = nullptr;
			}
			return *this;
		}

		Vector& operator= (Vector & rhs){
			std::cout << "Move operator..." << "\n";
			if (this != rhs) {
				capacity_size = rhs.capacity_size;
				curr_Size     = rhs.curr_Size;
				delete []ptr;
				ptr = new T[curr_Size];
				for (size_t i = 0; i < curr_Size; i++)
					this->ptr[i] = rhs.ptr[i];
			}
			return *this;
		}

		T& operator[](size_t index) {
			if (index > curr_Size) {
				std::cerr << "Out of bound index\n";
				exit(0);
			}
			return ptr[index];
		}

		~Vector() {
			if (ptr != nullptr) {
				delete[]ptr;
			}
		}

		void emplace_back(const T& data) {
			if (curr_Size == capacity_size) {
				expand();
			}
			ptr[curr_Size++] = data;
		}

		size_t size() const {
			return curr_Size;
		}

		Iterator begin() {
			return Iterator(ptr);
		}

		Iterator end() {
			return Iterator(ptr + curr_Size);
		}

	private:
		size_t capacity_size;
		size_t curr_Size;
		T* ptr;

		void expand() {
			capacity_size = capacity_size + capacity_size;
			T* temp_mem = new T[capacity_size];
			for (size_t i = 0; i < curr_Size; i++) {
				temp_mem[i] = ptr[i];
			}
			delete[]ptr;
			ptr = temp_mem;
		}

		void create_Memory() {
			ptr = new T[capacity_size];
		}
	};
};

void Disp(BALU::Vector<std::string> a) {
	std::cout << "Disp: ";
	for (size_t i = 0; i < a.size(); i++) {
		std::cout << a[i] << " ";
	}
	std::cout << "\n";
}

BALU::Vector<std::string> fill() {
	BALU::Vector<std::string> v;
	v.emplace_back(std::string("Balaji"));
	v.emplace_back(std::string("Mohan"));
	v.emplace_back(std::string("Darshan"));
	v.emplace_back(std::string("Maddy"));
	v.emplace_back(std::string("Preetha"));
	v.emplace_back(std::string("Ravi"));
	v.emplace_back(std::string("Shankar"));
	v.emplace_back(std::string("Malli"));
	v.emplace_back(std::string("Rani"));
	v.emplace_back(std::string("Govindaraj"));
	return v;
}


int main() {
	BALU::Vector<int> v;
	for (size_t i = 0; i < 16; i++)
		v.emplace_back(i);
	for (size_t i = 0; i < v.size(); i++)
		std::cout << v[i] << " ";
	std::cout << "\n";

	BALU::Vector<std::string> n;
	std::vector<std::string> s = {
		"Hello", "How", "are", "you", "?", "I", "am", "fine", "have", "a", "good", "day",
	};
	for (size_t i = 0; i < s.size(); i++) {
		n.emplace_back(s[i]);
	}
	for (size_t i = 0; i < s.size(); i++) {
		std::cout << n[i] << " ";
	}
	std::cout << "\n";

	//Copy Cons
	Disp(n);

	//Move Cons
	BALU::Vector<std::string> l = fill();
	for (size_t i = 0; i < l.size(); i++) {
		std::cout << l[i] << " ";
	}

	//Move Cons
	BALU::Vector<std::string> m(fill());
	for (auto it = m.begin(); it != m.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << "\n";
	return 0;
}