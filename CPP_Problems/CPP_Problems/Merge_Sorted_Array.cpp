#include<iostream>
#include<vector>

//frequently
//practice again
//impressed

//Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

//https://leetcode.com/problems/merge-sorted-array/

void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
	int total_Sum_Index = m + n - 1;
	int nums1_Size = m - 1;
	int nums2_Size = n - 1;
	while (nums1_Size > -1 && nums2_Size > -1) {
		nums1[total_Sum_Index--] = nums1[nums1_Size] > nums2[nums2_Size] ? nums1[nums1_Size--] : nums2[nums2_Size--];
	}

	while (nums1_Size > -1) {
		nums1[total_Sum_Index--] = nums1[nums1_Size--];
	}
	while (nums2_Size > -1) {
		nums1
			+[total_Sum_Index--] = nums2[nums2_Size--];;
	}
	return;
}

int main() {
	std::vector<int> m = { 3,5,7,0,0,0 };
	std::vector<int> n = { 1,4,8 };

	merge(m, 3, n, 3);

	for (const auto& val : m)
		std::cout << val << " ";
	std::cout << "\n";
	return 0;
}