#include<iostream>
#include<vector>

/* 
    Given an array of integers nums sorted in ascending order, 
   find the starting and ending position of a given target value
*/

// 0,1,2,3,4,5
// 5,7,7,8,8,10

//left mid right
//  0   2    5
//  3   4    5  
//  5        5

std::vector<int> serachRange(std::vector<int>& nums, int target) {
	std::vector<int> res = { -1, -1 };
	int left  = 0;
	int right = nums.size()-1;

	while (left <= right) {
		int mid = ((right - left) / 2) + left;
		if (nums[mid] == target) {
			int start = mid;
			int end   = mid;
			while (start - 1 >= left && nums[start - 1] == target) {
				--start;
			}

			while (end + 1 <= right && nums[end + 1] == target) {
				++end;
			}
			res = { start, end };
			return res;
		} 
		if (nums[mid] > target) right = mid - 1;
		else left = mid + 1;
	}
	return res;
}

int main() {
	std::vector<int> nums = { 5,7,7,8,8,10 };
	std::vector<int> res = serachRange(nums, 10);
	std::cout << "{ " << res[0] << ", " << res[1] << " } " << "\n";
	return 0;
}