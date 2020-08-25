#include<iostream>
#include<list>
#include<unordered_map>

//Frequently
//Practice again

//https://leetcode.com/problems/lru-cache/

/*
Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and put.
get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, 
it should invalidate the least recently used item before inserting a new item.
*/

class LRUCache {
public:
    LRUCache(int capacity) :nCapacity(capacity),nCount(0) {
        
    }

    int get(int key) {
        int ret = -1;
        const auto& it = u_Map.find(key);
        if (it != u_Map.end()) {
            dQueue.erase(it->second.second);
            ret = it->second.first;
            dQueue.push_front(key);
            it->second.second = dQueue.begin();
        }
        
        return ret;

    }

    void put(int key, int value) {
        const auto& it = u_Map.find(key);
        if (nCount < nCapacity) {
            if (it != u_Map.end()) {
                dQueue.erase(it->second.second);
            }
            else {
                ++nCount;
            }
            dQueue.push_front(key);
            u_Map[key] = { value, dQueue.begin() };
        }
        else {
            //Update existing key values
            if (it != u_Map.end()) {
                //Erase only key in dQueue
                dQueue.erase(it->second.second);
            } 
            //New key, so replace old_key
            else {
                const auto& del_key = *dQueue.rbegin();
                u_Map.erase(del_key);
                dQueue.pop_back();
            }
            dQueue.push_front(key);
            u_Map[key] = { value, dQueue.begin() };
        }

    }
private:
    const int nCapacity;
    int nCount;
    typedef int KEY;
    typedef int VALUE;
    std::list<KEY> dQueue;
    std::unordered_map<KEY, std::pair<VALUE, std::list<int>::iterator>> u_Map;
};

int main() {
#if 0   
    LRUCache cache(2 /* capacity */);

    cache.put(1, 1);
    cache.put(2, 2);
    std::cout << cache.get(1) << "\n";       // returns 1
    cache.put(3, 3);    // evicts key 2
    std::cout << cache.get(2) << "\n";       // returns -1 (not found)
    cache.put(4, 4);    // evicts key 1
    std::cout << cache.get(1) << "\n";       // returns -1 (not found)
    std::cout << cache.get(3) << "\n";       // returns 3
    std::cout << cache.get(4) << "\n";       // returns 4
#elif 0
    LRUCache cache(2 /* capacity */);
    cache.put(2, 1);
    cache.put(1, 1);
    std::cout << cache.get(2) << "\n";
    cache.put(4, 1);
    std::cout << cache.get(1) << "\n";
    std::cout << cache.get(2) << "\n";
#else
    LRUCache cache(2 /* capacity */);
    std::cout << cache.get(2) << "\n";
    cache.put(2, 6);
    std::cout << cache.get(1) << "\n";
    cache.put(1, 5);
    cache.put(1, 2);
    std::cout << cache.get(1) << "\n";
    std::cout << cache.get(2) << "\n";
#endif

    return 0;
}

