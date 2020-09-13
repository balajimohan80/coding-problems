#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>

//frequently
//practice again
/*
Roman numerals are represented by seven different symbols : I, V, X, L, C, Dand M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
For example, two is written as II in Roman numeral, 
just two one's added together. Twelve is written as, XII, which is simply X + II. 
The number twenty seven is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, 
the numeral for four is not IIII. Instead, the number four is written as IV. 
Because the one is before the five we subtract it making four. The same principle applies to the number nine, 
which is written as IX. There are six instances where subtraction is used:

Input: "IX"
Output: 9

Input: "LVIII"
Output: 58
Explanation: L = 50, V= 5, III = 3.

Input: "MCMXCIV"
Output: 1994
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.

*/

//Important Note:
//On this question, we must ask question to interviewer that input is always valid
//Example: 'III' is (1+1+1)3, but 'VVV' is not (5+5+5) 15, 15 is 'XV'  


int romanToInt(std::string& s) {
	const std::unordered_map<char, int> u_Map = {
		{'I' , 1},
		{'V',  5},
		{'X', 10},
		{'L', 50},
		{'C', 100},
		{'D', 500},
		{'M', 1000},
	};

	int integer_val = 0;
	
	size_t i = 0;
	while (i < s.length()) {
		const int curr_val   = u_Map.find(s[i])->second;
		const int next_val = (i + 1 < s.length()) ? u_Map.find(s[i + 1])->second : 0;
		if (curr_val >= next_val) {
			integer_val += curr_val;
		}
		else {
			integer_val += (next_val - curr_val);
			i++;
		}
		i++;
	}

	return integer_val;
}

int main() {
#if 0
	std::string s = "LVIII";
#elif 1
	std::string s = "MMCMLXXXIX";	
#endif

	std::cout << "Interger Val: " << romanToInt(s) << "\n";
	return 0;
}