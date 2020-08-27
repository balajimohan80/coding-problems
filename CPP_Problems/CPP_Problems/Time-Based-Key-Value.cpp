#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>

//

//Create a timebased key-value store class TimeMap, that supports two operations.
//The timestamps for all TimeMap.set operations are strictly increasing.

//https://leetcode.com/problems/time-based-key-value-store/

/* Observation:
   Do not use std::lower_bound or std::upper_bound, because we want "timestamp_prev <= timestamp"
   Example: [10 20]
   1.Timestamp:15, std::lower_bound rets 20, but we need 10 because 10 <= 15
   Also lower_bound or upper_bound rets forward_iterator, so we cannot go back line it-1.
*/
class TimeMap {
public:
    /** Initialize your data structure here. */
    TimeMap() {

    }

    void set(std::string key, std::string value, int timestamp) {
      //  auto& Val = str_Key_Val[key];
      //  std::pair<int, std::string> val = { timestamp, val };
      //  Val.emplace_back(std::pair<int, std::string>{timestamp, value});
        str_Key_Val[key].emplace_back(std::pair<int, std::string>{timestamp, value});
    }

    std::string get(std::string key, int timestamp) {
        const auto& IT = str_Key_Val.find(key);
#if 0     
        const auto& low_Bound = std::lower_bound(IT->second.begin(), IT->second.end(), timestamp, [](const data_t &a, int val)
            {
                return a.first <= val;
            });
#endif     
        return IT == str_Key_Val.end() ? "" : get_Lower_Bound(IT->second, timestamp);
    }
private:
    typedef std::pair<int, std::string> data_t;
    typedef std::vector<data_t> timeStamp_Val;
    typedef std::unordered_map<std::string, timeStamp_Val> u_Map;
    
    u_Map str_Key_Val;

    std::string get_Lower_Bound(const timeStamp_Val& vec, int timestamp) {
        int left = 0;
        int right = vec.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (timestamp < vec[mid].first) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }

        if (right == -1) {
            return "";
        }

        return vec[right].second;
    }
};

int main() {
    TimeMap kv;
#if 1
    kv.set("foo", "bar", 1);
    std::cout << kv.get("foo", 1) << "\n";
    std::cout << kv.get("foo", 3) << "\n";
    kv.set("foo", "bar2", 4);
    std::cout << kv.get("foo", 4) << "\n";
    std::cout << kv.get("foo", 5) << "\n";
#else
    kv.set("love", "high", 10);
    kv.set("love", "low", 20);
    std::cout << kv.get("love", 5) << "\n";
    std::cout << kv.get("love", 10) << "\n";
    std::cout << kv.get("love", 15) << "\n";
    std::cout << kv.get("love", 20) << "\n";
    std::cout << kv.get("love", 25) << "\n";
#endif
    return 0;
}


