#include<iostream>
#include<vector>

//practice again
//impressed

//https://leetcode.com/problems/find-all-duplicates-in-an-array/

//Given an array of integers, 1 ≤ a[i] ≤ n (n = size of array), 
//some elements appear twice and others appear once.
//Implement it  without extra space and in O(n) runtime

//For better explanation, refer
//https://leetcode.com/problems/find-all-duplicates-in-an-array/solution/

std::vector<int> findDuplicate(std::vector<int>& num) {
	std::vector<int> ret;
	for (size_t i = 0; i < num.size(); i++) {
		const auto val = std::abs(num[i]) - 1;
		if (num[val] < 0) {
			ret.push_back(std::abs(num[val]));
		}
		else {
			num[val] *= -1;
		}
	}
	return ret;
}

int main() {
	std::vector<int> num = { 4, 3, 2, 7, 8, 2, 3, 1 };
	std::vector<int> res = findDuplicate(num);

	std::cout << "Ret: ";
	for (const auto& val : res)
		std::cout << val << " ";
	std::cout << "\n";
	return 0;
}

