#include<iostream>
#include<vector>

//Practice again
//Impressed

//Given two sparse matrices A and B, return the result of AB.
//You may assume that A's column number is equal to B's row number.

//https://leetcode.com/problems/sparse-matrix-multiplication/

using namespace std;


/* Matrix multiplication formula
   A(l x m) * B(n x o) => C(l x o)
   Where:
   l -> Row of A's matrix
   m -> Column of A's matrix
   n -> Row of B's matrix
   o -> Column of B's matrix

   'm' must be equal to 'n', then res must be l x o

  A = [
		 [ (0,0), (0,1) ]
		 [ (1,0), (1,1) ]
	  ] (2 rows & 2 Col's)

B = [
	  [ (0,0), (0,1), (0,2) ],
	  [ (1,0), (1,1), (1,2) ],
	] (2 row's & 3 Col's)

'A' column(2) is equal to 'B' row(2), then C must have A's rows(2) x B's cols(3) => 6 

C = [ 
	  A(0,0)*B(0,0) + A(0,1)*B(1,0)   A(0,0)*B(0,1) + A(0,1)*B(1,1)  A(0,0)*B(0,2) + A(0,1)*B(1,2)   
	  A(1,0)*B(0,0) + A(1,1)*B(1,0)   A(1,0)*B(0,1) + A(1,1)*B(1,1)  A(1,0)*B(0,2) + A(1,1)*B(1,2)	
    ]

 */
vector<vector<int>> multiply(const vector<vector<int>>& A, const vector<vector<int>>& B) {
	const size_t l = A.size();    //Row 
	const size_t m = A[0].size(); //Col's
	const size_t n = B.size();    //Row
	const size_t o = B[0].size(); // Col's

	vector<vector<int>> C(l, vector<int>(o, 0));

	for (size_t i = 0; i < l; i++) {   /* l */
		for (size_t j = 0; j < m; j++) { /* m */
			if (A[i][j] != 0) {
				for (size_t k = 0; k < o; k++) { /* o */
					C[i][k] += (A[i][j] * B[j][k]);
				}
			}
		}
	}
	return C;
}


int main() {
	vector<vector<int>> A = {
		{ 1, 0, 0  },
		{ -1, 0, 3 }
	};

	vector<vector<int>> B = {
		{7, 0, 0 } ,
		{0, 0, 0 },
		{0, 0, 1 }
	};

	vector<vector<int>> C = multiply(A, B);

	std::cout << "{ \n";
	for (size_t i = 0; i < C.size(); i++) {
		std::cout << " { ";
		for (size_t j = 0; j < C[i].size(); j++) {
			std::cout << C[i][j] << " ";
		}
		std::cout << " } \n";
	}
	std::cout << "}\n";
	return 0;
}




