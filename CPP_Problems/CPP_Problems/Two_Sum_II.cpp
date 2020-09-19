#include<iostream>
#include<vector>


//https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

/*
Given an array of integers that is already sorted in ascending order, 
find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, 
where index1 must be less than index2.

Example 1:
Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
Explanation: The sum of 2 and 7 is 9. Therefore index1 = 1, index2 = 2.

Example 2:
Input: numbers = [2,3,4], target = 6
Output: [1,3]

Example 3:
Input: numbers = [-1,0], target = -1
Output: [1,2]

*/

std::vector<int> twoSum(std::vector<int>& nums, const int target) {
	std::vector<int> ret = { -1, -1 };
	int left   = 0;
	int right = nums.size() - 1;
	while (left <right) {
		int sum = nums[left] + nums[right];
		if (sum == target) {
			ret[0] = left + 1;
			ret[1] = right + 1;
			break;
		}

		(sum > target) ? --right : ++left;

	}
	return ret;
}


int main() {
	std::vector<int> nums = { 2,7,11,15 };
	const int target_sum = 20;

	std::vector<int> ret = twoSum(nums, target_sum);
	for (const auto val : ret)
		std::cout << val << " ";
	std::cout << "\n";
	return 0;
}