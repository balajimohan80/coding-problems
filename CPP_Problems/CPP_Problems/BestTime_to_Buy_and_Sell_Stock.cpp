#include<iostream>
#include<vector>

//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

//frequently
//practice again

/*
Say you have an array prices for which the ith element is the price of a given stock on day i.
Design an algorithm to find the maximum profit. You may complete as many transactions as you like 
(i.e., buy one and sell one share of the stock multiple times).

Input: [7,1,5,3,6,4]
Output: 7

Buy on day-2 which is 1 and sell on day-3, profit is 5-1 = 4
Buy on day-4 which is 3 and sell on day-4, profit is 6-3 = 3
Therefore total profit is 4+3 => 7

*/

//Please refer https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/solution/
// Its a peak, valley approach

int maxProfit(std::vector<int>& prices) {
	int total_profit = 0;

	for (size_t i = 0; i < prices.size(); i++) {
		//First identify Valley
		while (i + 1 < prices.size() && prices[i] >= prices[i + 1]) {
			i++;
		}
		const int valley = prices[i];
		//Identify peak
		while (i + 1 < prices.size() && prices[i] <= prices[i + 1]) {
			i++;
		}
		const int peek = prices[i];
		total_profit += (peek - valley);
	}
	return total_profit;
}

int main() {
#if 0
	std::vector<int> stocks_Price = { 7,1,5,3,6,4 };
#elif 0
	std::vector<int> stocks_Price = { 1,2,3,4,5 };
#elif 0
	std::vector<int> stocks_Price = { 7,6,4,3,1 };
#else
	std::vector<int> stocks_Price = {2,4,1};
#endif
	std::cout << "Max_Profit: " << maxProfit(stocks_Price) << "\n";
	return 0;
}







