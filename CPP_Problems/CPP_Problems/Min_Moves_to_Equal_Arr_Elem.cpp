#include<iostream>
#include<vector>
#include<algorithm>

int minMoves_Sol_1(std::vector<int> nums) {
	std::sort(nums.begin(), nums.end());
	int count = 0;
	for (size_t i = nums.size() - 1; i > 0; i--) {
		count += nums[i] - nums[0];
	}
	return count;
}

int minMoves_Sol_2(std::vector<int> nums) {
	int count = 0;

	while (true) {
		int min = nums[0];
		int max = nums[0];

		for (auto& val : nums) {
			if (val < min) min = val;
			if (val > max) max = val;
		}
		int diff = max - min;
		if (!diff) break;
		count += diff;
		for (size_t i = 0; i < nums.size(); i++) {
			if (nums[i] != max) {
				nums[i] += diff;
			}
		}
	}
	return count;
}

//1,2,3
//2,3,3
//3,4,3
//4,4,4

//2,4,6,8
//3,5,7,8
//4,6,8,8
//5,7,9,8
//6,8,9,9
//7,9,9,10
//8,10,10,10
//9,11,11,10
//10,12,11,11
//11,13,12,11
//12,13,13,12
//13,13,14,13
//14,14,14,14

int minMoves_Sol_3(std::vector<int> nums) {
	int min_val = std::numeric_limits<int>::max();
	for (auto& val : nums) {
		min_val = min_val < val ? min_val : val;
	}
	int ret = 0;
	for (auto& val : nums) {
		ret += val - min_val;
	}
	return ret;
}

int main() {
	//std::vector<int> nums = { 1,2,3,4 };
	std::vector<int> nums = { 2,4,6,8 };
	std::cout << "Count = " << minMoves_Sol_1(nums) << "\n";
	std::cout << "Count = " << minMoves_Sol_2(nums) << "\n";
	std::cout << "Count = " << minMoves_Sol_3(nums) << "\n";

	return 0;
}