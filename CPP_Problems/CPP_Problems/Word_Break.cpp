#include<iostream>
#include<string>
#include<vector>

//frequently
//practice again

//https://leetcode.com/problems/word-break/

/*
Given a non-empty string s and a dictionary wordDict containing a list of non-empty words,
determine if s can be segmented into a space-separated sequence of one or more dictionary words.
*/

//DP


int main() {
	std::string s = { "leetcode" };
	std::vector<std::string> wordDict = {"leet", "code"};
	//for (int  j = 0 ; j < s.length(); j++)
	for (int i = 0; i < s.length(); i++) {
		std::cout << "Sub: " << s.substr(i, s.size()) << " c:  " << s.substr(i, s.size()).compare(wordDict[0]);
		std::cout << " c: " << s.substr(i, s.size()).compare(wordDict[1]) << "\n";
	}
	return 0;
}