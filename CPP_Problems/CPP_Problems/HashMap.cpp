#include<iostream>
#include<vector>
#include<list>

//frequently
//Practice again
//impressed

//https://leetcode.com/problems/design-hashmap


class MyHashMap {
public:
	MyHashMap() :map(mod_Prime_Num, std::list<data_t>()) {};

	void put(int key, int value) {
		const int mod_Val = key % mod_Prime_Num;
		auto& list = map[mod_Val];
		auto it = find(list, key);
		if (it != list.end()) {
			it->second = value;
		}
		else {
			list.push_back(data_t{key, value});
		}
	}

	int get(int key) {
		const int mod_val = key % mod_Prime_Num;
		auto& list = map[mod_val];
		auto it = find(list, key);
		return it == list.end() ? -1 : it->second;
	}

	void remove(int key) {
		const int mod_val = key % mod_Prime_Num;
		auto& list = map[mod_val];
		auto it = find(list, key);
		if (it != list.end()) {
			list.erase(it);
		}
	}

private:
	const int mod_Prime_Num = 2069;
	typedef int key_t;
	typedef int val_t;
	typedef std::pair<key_t, val_t> data_t;
	std::vector<std::list<data_t>> map;
	
	std::list<data_t>::iterator find(std::list<data_t>& list, int key) {
		auto begin = list.begin();
		auto end = list.end();
		while (begin != end) {
			if (begin->first == key)
				return begin;
			++begin;
		}
		return end;
	}

};

int main() {
	MyHashMap m;
	m.put(1, 1);
	m.put(2, 2);
	std::cout << m.get(1) << "\n";
	std::cout << m.get(3) << "\n";
	m.put(2, 1);
	std::cout << m.get(2) << "\n";
	m.remove(2);
	std::cout << m.get(2) << "\n";
	return 0;
}

