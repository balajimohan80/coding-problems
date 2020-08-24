#include<iostream>
#include<vector>

//Practice again

/* Given an integer array nums, find the contiguous subarray (containing at least one number) 
   which has the largest sum and return its sum.

   To refer: https://www.youtube.com/watch?v=86CQq3pKSUw
*/

int inline max(int i,  int  j) {
	return (i > j) ? i : j;
}

int maxSubArray(const std::vector<int>& nums) {
	int max_SubArray;
	int max_SubArray_Global_Sum;
	max_SubArray_Global_Sum = max_SubArray = nums[0];
	
	for (const auto& val : nums) {
		max_SubArray = max(val, max_SubArray+val);
		max_SubArray_Global_Sum = max(max_SubArray_Global_Sum, max_SubArray);
	}
	return max_SubArray_Global_Sum;
}


int main() {
	std::vector<int> nums = { -2,1,-3,4,-1,2,1,-5,4 };
	std::cout << "MaxSum: " << maxSubArray(nums) << "\n";
	return 0;
}