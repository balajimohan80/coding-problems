#include<iostream>
#include<vector>


//Practice again

//https://leetcode.com/problems/transpose-matrix/


std::vector<std::vector<int>> transpose(std::vector<std::vector<int>>& A) {
	const size_t row_Size = A.size();
	const size_t col_Size = A[0].size();

	std::vector<std::vector<int>> res(col_Size, std::vector<int>(row_Size));

	for (size_t row = 0; row < row_Size; row++) {
		for (size_t col = 0; col < col_Size; col++) {
			res[col][row] = A[row][col];
		}
	}
	return res;
}

int main() {
#if 0
	std::vector<std::vector<int>> res = {
		{1,2,3},
		{4,5,6},
		{7,8,9},
	};
#else
	std::vector<std::vector<int>> res = {
		{1,2,3} ,
		{4,5,6} ,
	};
#endif
	res = transpose(res);

	for (const auto& row : res) {
		for (const auto& data : row) {
			std::cout << data << " ";
		}
		std::cout << "\n";
	}
	return 0;
}