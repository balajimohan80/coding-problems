#include<iostream>
#include<vector>

//https://leetcode.com/problems/move-zeroes/

void moveZeroes(std::vector<int>& nums) {
	size_t  i = 0;
	for (size_t j = 0; j < nums.size(); j++) {
		if (nums[j]) {
			nums[i++] = nums[j];
		}
	}
	while (i < nums.size()) {
		nums[i++] = 0;
	}

}

int main() {
	std::vector<int> num = {0, 0, 0, 0, 1};
	moveZeroes(num);
	for (auto& i : num) {
		std::cout << i << " ";
	}
	std::cout << "\n";
	return 0;
}
