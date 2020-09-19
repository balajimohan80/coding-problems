#include<iostream>
#include<vector>
#include<algorithm>
//https://leetcode.com/problems/intersection-of-two-arrays-ii/

//Given two arrays, write a function to compute their intersection.


std::vector<int> intersect(std::vector<int>& nums1, std::vector<int>& nums2) {
	std::sort(nums1.begin(), nums1.end());
	std::sort(nums2.begin(), nums2.end());
	std::vector<int> res;

	size_t i = 0;
	size_t j = 0;

	while (i < nums1.size() && j < nums2.size()) {
		if (nums1[i] == nums2[j]) {
			res.push_back(nums1[i]);
			i++; j++;
		}
		else {
			nums1[i] < nums2[j] ? ++i : ++j;
		}
	}
	return res;
}


int main() {
	std::vector<int> nums1 = { 4, 9, 5 };
	std::vector<int> nums2 = { 9,4,9,8,4 };
	std::vector<int> res = intersect(nums1, nums2);

	for (auto& val : res)
		std::cout << val << " ";
	std::cout << "\n";
	return 0;
}

