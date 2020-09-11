#include<iostream>
#include<vector>

//practice again
//frquently
//impressed


//https://leetcode.com/problems/squares-of-a-sorted-array/

/*
Given an array of integers A sorted in non - decreasing order, 
return an array of the squares of each number, also in sorted non - decreasing order.
*/


std::vector<int> sortedSquares(std::vector<int>& A) {
	std::vector<int> res(A.size());

	int negative_End_Index = -1;

	for (const auto& val : A) {
		if (val >= 0) break;
		negative_End_Index++;
	}

	int positive_Start_Index = negative_End_Index+1;

	size_t i = 0;
	while (negative_End_Index > -1 && positive_Start_Index < A.size()) {
		const int negtive_Sq_Val  = A[negative_End_Index] * A[negative_End_Index];
		const int positive_Sq_Val = A[positive_Start_Index] * A[positive_Start_Index];
		res[i++] = negtive_Sq_Val < positive_Sq_Val ?
			A[negative_End_Index] * A[negative_End_Index] :
			A[positive_Start_Index] * A[positive_Start_Index];
		negtive_Sq_Val < positive_Sq_Val ? --negative_End_Index : positive_Start_Index++;
	}

	while (negative_End_Index > -1) {
		res[i++] = A[negative_End_Index] * A[negative_End_Index];
		negative_End_Index--;
	}

	while (positive_Start_Index < A.size()) {
		res[i++] = A[positive_Start_Index] * A[positive_Start_Index];
		positive_Start_Index++;
	}
	return res;
}

int main() {
	std::vector<int> A = { 2,3,10 };
  	std::vector<int> res = sortedSquares(A);

	for (const auto& val : res)
		std::cout << val << " ";
	std::cout << "\n";
	return 0;
}