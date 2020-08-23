#include<iostream>
#include<vector>

//Practice again

//https://leetcode.com/problems/search-in-rotated-sorted-array/solution/

/*Given an integer array nums sorted in ascending order, and an integer target.
Suppose that nums is rotated at some pivot unknown to you beforehand (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
You should search for target in nums and if you found return its index, otherwise return -1.
*/

//4, 5, 6, 7, 0, 1, 2   -> Num
//0, 1, 2, 3, 4, 5, 6   -> Index

//Target is 0
//left  Mid  right
// 0     3    6
// 4     5    6
// 4     4    5   

//Target is 3
//Left Mid  Right
// 0    3     6
// 0    1     2
// 0    0     1
// 0          0

//Target is 4
//Left Mid Right
// 0    3   6
// 0    1   2
// 0    0   1

int search(std::vector<int>& nums, int target) {
	int left = 0;
	int right = nums.size() - 1;
	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (nums[mid] == target) return mid;
		if (nums[left] <= nums[mid]) {
			if (target >= nums[left] && target <= nums[mid]) {
				right = mid - 1;
			}
			else {
				left = mid + 1;
			}
		}
		else {
			if (target <= nums[right] && target >= nums[mid]) {
				left = mid + 1;
			}
			else {
				right = mid - 1;
			}
		}
	}
	return -1;
}

int main() {
	//std::vector<int> nums = { 4,5,6,7,0,1,2 };
	std::vector<int> nums = { 5, 1, 3 };
	for (int i = 0; i < 9; i++)
	std::cout << i << ": " << "Res: " << search(nums, i) << "\n";
	return 0;
}