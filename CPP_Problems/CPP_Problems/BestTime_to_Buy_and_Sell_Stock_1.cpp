#include<iostream>
#include<vector>

//https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

//frequent

/*
Say you have an array for which the ith element is the price of a given stock on day i.
If you were only permitted to complete at most one transaction 
(i.e., buy one and sell one share of the stock), design an algorithm to find the maximum profit.
*/


int maxProfit(std::vector<int>& prices) {
	int valley = std::numeric_limits<int>::max();
	int peak   = -1;
	int max_Profit = 0;
	for (auto& stock_price : prices) {
		if (valley > stock_price) {
			valley = stock_price;
			peak   = -1;
		}
		else if (peak < stock_price) {
			peak = stock_price;
			max_Profit = peak - valley > max_Profit ? peak - valley : max_Profit;
		}
	}
	return max_Profit;
}

int main() {
	//std::vector<int> nums = { 7,3,5,3,7,4,2,5,10};
	std::vector<int> nums = { 7,6,5,4,3,4,5,6,7,2,8,10 };
	std::cout << "MaxProfit: " << maxProfit(nums) << "\n";
	return 0;
}