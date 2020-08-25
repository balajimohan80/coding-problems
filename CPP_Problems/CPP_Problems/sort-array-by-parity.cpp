#include<iostream>
#include<vector>


//https://leetcode.com/problems/sort-array-by-parity/

/* Given an array A of non-negative integers, return an array consisting of all the even elements of A, 
   followed by all the odd elements of A.
*/

std::vector<int> sortArrayByParity(std::vector<int>& A) {
	int left = 0;
	int right = A.size() - 1;

	while (left < right && A[right] & 1) {
		--right;
	}
	while (left < right && !(A[left] & 1)) {
		++left;
	}

	while (left < right) {
		if (A[left] & 1) {
			while (left < right && A[right] & 1) {
				--right;
			}
			std::swap(A[left++], A[right--]);
		}
		else {
			left++;
		}
	}
	return A;
}

int main() {
	std::vector<int> nums = { 4,1,2,1 };
	//std::vector<int> nums = { 0 };
	//std::vector<int> nums = { 1, 3, 0, 5, 2 };
	std::vector<int> out = sortArrayByParity(nums);

	for (const auto& val : out) {
		std::cout << val << " ";
	}
	std::cout << "\n";
	return 0;
}
