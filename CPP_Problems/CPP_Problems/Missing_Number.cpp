#include<iostream>
#include<vector>


//https://leetcode.com/problems/missing-number/

/*
Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, 
find the one that is missing from the array.
*/

int missingNumber(std::vector<int>& nums) {
	long total_val = 0;
	int n = 0;

	for (const auto& val : nums) {
		total_val += val;
		n = (val > n) ? val : n;
	}
	//To find arthimetic sequence of n: n(n+1)/2
	long cal_Val = (n * (n + 1)) / 2;
	return cal_Val - total_val;
}

int main() {
#if 0	
	std::vector<int> nums = { 3, 0, 1 };
#else
	std::vector<int> nums = { 9,6,4,2,3,5,7,1,8 };
#endif
	std::cout << "Missing num: " << missingNumber(nums) << "\n";
	return 0;
}