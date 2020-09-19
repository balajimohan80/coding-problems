#include<iostream>
#include<vector>


//frequent
//practice again

//https://leetcode.com/problems/climbing-stairs/

/*
You are climbing a stair case. It takes n steps to reach to the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Example 1:
Input: 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps

Example 2:
Input: 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step

*/

/*
This is clearly a fibonacci sequence.

Let's assume we have max of 4 stairs.
maximum number of sequence to reach 4th or last stairs.
Maximum you can 2 steps.

From step-0 to reach step-1: 1
From step-0 to reach step-2: 1,1 or 2 =>total 2

From Step-0 to reach step-3: 
To reach 3, there are two possible options either from step no-1 or step no-2.
So we copy sequences from step-0 to step-1, which is 1
Copy sequences  from step-0 to step-2, whihc is 1,1 & 2

1         
1,1        
2

Now from step-1, to reach step-3 is only 2 (3-1), therefore add 2 from  step-0 to step-1
1,2
Now from step-2, to reach step-3 is only 1 (2-1), therefore add 1 from  step-0 to step-2
1,1,1
2,1

Therefor total possible options to reach step-3 from step-0 is given 3 and sequences are given below:
1,2
1,1,1
2,1 

from step-0 to step-4:
To reach step-4, neary by steps are 2 & 3. So copy the sequences from step-2 & 3.

Step-2 sequences:
1,1
2
Step-3 sequences:
1,2
1,1,1
2,1

From Step-2, to reach step-4 is 2 (4-2), therefor add 2 in step-2 sequences:
Step-2 sequences:
1,1,2
2,2
From Step-3, to reach step-4 is 1 (4-3), therefor add 1 in step-3 sequences:
Step-2 sequences:
1,2,1
1,1,1,1
2,1,1
Therefore total no of options to reach step-4 is 5 given below:
1,1,2
2,2
1,2,1
1,1,1,1
2,1,1

Finally it concludes that its a fibonacci sequences
*/


int climbStairs(int n) {
	std::vector<int> memoization(n + 1);
	memoization[0] = 1;
	memoization[1] = 1;

	for (size_t i = 2; i <= n; i++) {
		memoization[i] = memoization[i - 2] + memoization[i - 1];
	}
	return memoization[n];
}



int main() {
	std::cout << climbStairs(3) << "\n";
	return 0;
}