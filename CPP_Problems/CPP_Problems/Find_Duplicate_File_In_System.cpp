#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>


//techniques: string parsing
//https://leetcode.com/problems/find-duplicate-file-in-system/

/*
Given a list of directory info including directory path, and all the files with contents 
in this directory, 
you need to find out all the groups of duplicate files in the file system 
in terms of their paths.
*/


using namespace std;
#if 0
vector<vector<string>> findDuplicate(vector<string>& paths) {
	
	unordered_map<string, vector<string>> u_Map;
	for (const auto& str : paths) {
		size_t pos_1 = str.find(" ");
		if (pos_1 != string::npos) {
			string dir = str.substr(0, pos_1);
			string rest = str.substr(pos_1, str.size());
			
			while (rest.size()) {
				size_t pos_2  = rest.find("(")+1;
				size_t pos_3  = rest.find(")", pos_2);
				string content = rest.substr(pos_2, pos_3-pos_2);
				string f_name = dir+ "/" + rest.substr(1, pos_2-2);
				u_Map[content].emplace_back(f_name);
		//		std::cout << "F_Name: " << f_name << " Content: " << content << "\n";

				rest = rest.substr(pos_3+1, rest.size()-pos_3);
			}
		}
	}

	vector<vector<string>> ret;

	size_t i = 0;
	unordered_map<string, vector<string>>::iterator begin = u_Map.begin();
	unordered_map<string, vector<string>>::iterator end   = u_Map.end();

	while (begin != end) {
		if (begin->second.size() > 1)
		ret.push_back(begin->second);
		++begin;
	}

	return ret;
}
#else
vector<vector<string>> findDuplicate(vector<string>& paths) {
	unordered_map<string, vector<string>> u_Map;

	for (const auto& str : paths) {
		size_t pos_1 = str.find(" ");
		if (pos_1 != string::npos) {
			string dir_Name = str.substr(0, pos_1);
			string rest_of_str = str.substr(pos_1 + 1, str.size() - pos_1);
			while (rest_of_str.size()) {
				size_t pos_2   = rest_of_str.find(".txt");
				pos_2 += 4;
				string f_name = (rest_of_str[0] == ' ') ? rest_of_str.substr(1, pos_2-1) : rest_of_str.substr(0, pos_2);
				pos_2++;
				rest_of_str = rest_of_str.substr(pos_2, rest_of_str.size() - pos_2);
				size_t pos_3 = rest_of_str.find(")");
				string content = rest_of_str.substr(0, pos_3);
				++pos_3;
				rest_of_str = rest_of_str.substr(pos_3, rest_of_str.size()- pos_3);
				f_name = dir_Name + "/" + f_name;
				u_Map[content].emplace_back(f_name);
			}
		}
	}
	vector<vector<string>> ret;
	for (auto const& it : u_Map) {
		if (it.second.size() > 1) {
			ret.emplace_back(it.second);
		}
	}
	return ret;
}
#endif



int main() {
#if 0
	vector<string> in = {
		{"root/a 1.txt(abcd) 2.txt(efgh)", "root/c 3.txt(abcd)",
		"root/c/d 4.txt(efgh)", "root 4.txt(efgh)"}
	};
#else
	vector<string> in = { "root/a 1.txt(abcd) 2.txt(efsfgh)", "root/c 3.txt(abdfcd)", "root/c/d 4.txt(efggdfh)" };
#endif
	vector<vector<string>> ret = findDuplicate(in);
	for (const auto &v_Str : ret) {
		for (const auto& str : v_Str) {
			std::cout << str << " ";
		}
		std::cout << "\n";
	}
	return 0;
}