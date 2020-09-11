#include<iostream>
#include<vector>

//frequently
//practice again
//Impressed
//https://leetcode.com/problems/single-number/

//Given a non-empty array of integers, every element appears twice except for one. 
//Find that single one.
//Your algorithm should have a linear runtime complexity. 
//Could you implement it without using extra memory?


int singleNumber(std::vector<int>& nums) {
	int x_OR = 0;;
	
	for (const auto& val : nums) {
		x_OR = x_OR ^ val;
	}
	return x_OR;
}

int main() {
	//std::vector<int> nums = { 2,2,1 };
	std::vector<int> nums = { 4,1,2,1,2 };
	std::cout << singleNumber(nums) << "\n";
	return 0;
}