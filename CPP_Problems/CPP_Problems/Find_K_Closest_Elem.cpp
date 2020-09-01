#include<iostream>
#include<vector>
#include<algorithm>

//Impressed
//frequently

#define min(a,b) a < b ? a : b;

std::vector<int> find_K_Closest_Elem(std::vector<int>& num, int k, const int x) {
	int left  = 0;
	int right = num.size();

	while (left <= right) {
		const int mid = left + ((right - left) >> 1);

		if (x > num[mid]) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}

	right = (right < 0) ? 0 : right;

	int left_Max_Window  = std::max(0, right - k);
	int right_Min_Window = min(num.size() - 1, right + k);
	int temp = k;
	while (right_Min_Window-left_Max_Window >= k) {
		if (std::abs(num[left_Max_Window] - x) > std::abs(num[right_Min_Window] - x)) {
			left_Max_Window++;
		}
		else {
			right_Min_Window--;
		}
	}

	std::vector<int> ret(temp);
	std::copy(num.begin() + left_Max_Window, num.begin() + right_Min_Window+1, ret.begin());
	return ret;
}


int main() {
	std::vector<int> num = { 1,2,3,4,5 };
	std::vector<int> out = find_K_Closest_Elem(num, 4, -1);

//	std::vector<int> num = { 1 };
//	std::vector<int> out = find_K_Closest_Elem(num, 1, 1);

//	std::vector<int> num = { 1,1,1,10, 10, 10 };
//	std::vector<int> out = find_K_Closest_Elem(num, 1, 9);


	for (const auto x : out) {
		std::cout << x << " ";
	}
	std::cout << "\n";
	return 0;
}