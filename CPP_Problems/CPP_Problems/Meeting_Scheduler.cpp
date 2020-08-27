#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//Impressed
//Practice again

/*Given the availability time slots arrays slots1 and slots2 of two people and a meeting duration duration,
  return the earliest time slot that works for both of them and is of duration duration.
  If there is no common time slot that satisfies the requirements, return an empty array.
  The format of a time slot is an array of two elements [start, end] representing an inclusive 
  time range from start to end.  
  It is guaranteed that no two availability slots of the same person intersect with each other. 
  That is, for any two time slots [start1, end1] and [start2, end2] of the same person, 
  either start1 > end2 or start2 > end1.
*/
//https://leetcode.com/problems/meeting-scheduler/

//algorithm to find overlapping or intersecting is given in following site:
//http://mikekchar.github.io/portfolio//OverlappingLines

vector<int> overLapping(const vector<int>& s1, const vector<int>& s2) {
	vector<int> ov_Lapping(2);
	
	//Max
	ov_Lapping[0] = s1[0] > s2[0] ? s1[0] : s2[0];
	
	//Min
	ov_Lapping[1] = s1[1] < s2[1] ? s1[1] : s2[1];
	return ov_Lapping;
}

vector<int> 
minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {

	size_t s1_Index = 0;
	size_t s2_Index = 0;

	std::sort(slots1.begin(), slots1.end());
	std::sort(slots2.begin(), slots2.end());


	vector<int> temp;
	while (s1_Index < slots1.size() && s2_Index < slots2.size()) {
		temp = overLapping(slots1[s1_Index] , slots2[s2_Index]);
		if (temp[0] < temp[1] && temp[1] - temp[0] >= duration) {
			return { temp[0], temp[0] + duration };
		}
		if (slots1[s1_Index][1] == temp[1]) {
			s1_Index++;
		}
		else if (slots2[s2_Index][1] == temp[1]) {
			s2_Index++;
		}
	}

	return {};
}

int main() {
#if 0
	vector<vector<int>> slots1 = { {10, 50},{60, 120},{140, 210} };
	vector<vector<int>> slots2 = { {0,15 }, { 60,70 }};
	int duration = 8;
#elif 0
	vector<vector<int>> slots1 = { {0, 2} };
	vector<vector<int>> slots2 = { {1, 3} };
	int duration = 1;
#else
	vector<vector<int>> slots1 = { {216397070,363167701},{98730764,158208909},{441003187,466254040},
		{558239978,678368334},{683942980,717766451} };
	vector<vector<int>> slots2 = { {50490609, 222653186}, { 512711631, 670791418 }, { 730229023, 802410205 }, { 812553104, 891266775 },
		{ 230032010, 399152578 }};
	int duration = 456085;
#endif
	vector<int> ret = minAvailableDuration(slots1, slots2, duration);
	if (ret.size())
		std::cout << "{ " << ret[0] << ", " << ret[1] << " }\n";
	else
		std::cout << "{ }\n";
	return 0;
}