#include<iostream>
#include<vector>


int find_Closest_num(const std::vector<int>& num, int target) {
	int left  = 0;
	int right = num.size() - 1;
	int mid;
	while (left <= right) {
		mid = left + ((right - left) >> 1);
		if (target <= num[mid]) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}

	if (right == -1) return num[0];

	if (right + 1 < num.size()) {
		return (std::abs(num[right] - target) < std::abs(num[right + 1] - target)) ? num[right] : num[right + 1];
	}
	return num[right];
}


int main() {
	std::vector<int> num = { 5, 10, 13, 18, 25, 27, 30 };
//	find_Closest_num(num, 11);
	for (int i = 0; i < 40; i++) {
		std::cout << "num: " << i << " " << find_Closest_num(num, i) << "\n";
	}
	return 0;
}