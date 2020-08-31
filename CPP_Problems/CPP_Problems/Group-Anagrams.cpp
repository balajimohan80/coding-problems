#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>

/*
Given an array of strings, group anagrams together.
*/


//https://leetcode.com/problems/group-anagrams/

std::string calculte_Val(const std::string& str) {
	unsigned int a['z' - 'a' + 1] = { 0 };
	for (size_t i = 0; i < str.length(); i++) {
		++a[str[i] - 'a'];
	}
	std::string ret;
	for (size_t i = 0; i < 26; i++) {
		if (a[i]) {
			std::string int_char = "#" + std::to_string(a[i]);
			ret += int_char;
		}
		else {
			ret += "#0";
		}
	}
	std::cout << ret << "\n";
	return ret;
}

std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
	std::unordered_map<std::string, std::vector<std::string>> cal_Val;

	
	size_t i = 0;
	for (const auto& val : strs) {
		cal_Val[calculte_Val(val)].emplace_back(val);
	}

	std::vector<std::vector<std::string>> ret(cal_Val.size());

	auto it_Begin = cal_Val.begin();
	auto it_End = cal_Val.end();

	i = 0;
	while (it_Begin != it_End) {
		ret[i++] = it_Begin->second;
		it_Begin++;
	}

	return ret;
}

int main() {
	std::vector<std::string> input = { "eat", "tea", "tan", "ate", "nat", "bat" };
	std::vector<std::vector<std::string>> ret = groupAnagrams(input);
	for (const auto val : ret) {
		for (const auto dat : val) {
			std::cout << dat << " ";
		}
		std::cout << "\n";
	}

	return 0;
}