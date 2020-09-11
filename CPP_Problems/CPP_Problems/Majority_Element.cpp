#include<iostream>
#include<vector>


//practice again
//impressed

//https://leetcode.com/problems/majority-element

/*
Given an array of size n, find the majority element. 
The majority element is the element that appears more than ⌊ n/2 ⌋ times.
*/

//Boyer-Moore Voting Algorithm

int find_Candidate(const std::vector<int>& nums) {
	int candidate = nums[0];
	size_t count = 1;

	for (size_t i = 1; i < nums.size(); i++) {
		if (candidate == nums[i]) {
			++count;
		}
		else {
			--count;
			if (!count) {
				count = 1;
				candidate = nums[i];
			}
		}
	}
	return candidate;
}

bool is_It_Majority(const std::vector<int>& nums, const int candidate, const size_t count) {
	size_t i = 0;
	for (const auto& val : nums) {
		i = (val == candidate) ? i + 1 : i;
	}
	return i >= count ? true : false;
}

int majorityElement(std::vector<int>& nums) {
	int candidate = find_Candidate(nums);
	size_t majority_count = nums.size() / 2 + 1;
	return is_It_Majority(nums, candidate, majority_count) == true ? candidate : -1;
}



int main() {
	std::vector<int> nums = { 2,2,1,1,1,2,2 };
	std::cout << majorityElement(nums) << "\n";
	return 0;
}