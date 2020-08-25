#include<iostream>
#include<vector>
#include<unordered_map>

//Frequently
//Practice again

/* Given an array of integers, return indices of the two numbers such that they add up to a specific target.
   You may assume that each input would have exactly one solution, and you may not use the same element twice.
*/

//https://leetcode.com/problems/two-sum/

typedef int DIFF;
typedef int INDEX;
std::vector<int> twoSum(std::vector<int>& nums, int target) {
	std::unordered_map<DIFF, INDEX> u_Map;

	int i = 0;
	for (const auto& val : nums) {
		if (u_Map.find(val) == u_Map.end()) {
			const int diff = target - val;
			u_Map[diff] = i;
		} 
		else {

			return { u_Map[val], i };
		}

		i++;
	}
	return { -1, -1 };
}

int main() {
//	std::vector<int> nums = { 2, 7, 11, 15 };
//	std::vector<int> res = twoSum(nums, 9);

//	std::vector<int> nums = { 11, 7, 2, 8, 3, 4};
//	std::vector<int> res = twoSum(nums, 12);

	std::vector<int> nums = { -1,-2,-3,-4,-5 };
	std::vector<int> res = twoSum(nums, -8);

	std::cout << "[ " << res[0] << ", " << res[1] << " ]" << "\n";
	return 0;
}

