#include<iostream>
#include<vector>
#include<stack>

//practice again
//Impressed

//https://leetcode.com/problems/daily-temperatures/

/*
Given a list of daily temperatures T, return a list such that, for each day in the input, 
tells you how many days you would have to wait until a warmer temperature. 
If there is no future day for which this is possible, put 0 instead.

For example, given the list of temperatures T = [73, 74, 75, 71, 69, 72, 76, 73], 
your output should be                           [1, 1, 4, 2, 1, 1, 0, 0].
*/


/* For better explanation, please refer:
   	https://www.youtube.com/watch?v=WGm4Kj3lhRI&ab_channel=AlexanderLe
*/


std::vector<int> dailyTemperatures(std::vector<int>& T) {
    int size = T.size() - 1;
    typedef int Temperature_t;
    typedef int Index_t;
    std::stack<std::pair<Temperature_t, Index_t>> st;
    std::vector<int> res(T.size(), 0);
    st.push(std::pair<Temperature_t, Index_t >{ T[size], size });
    --size;
    while (size > -1) {
        while (!st.empty() && st.top().first < T[size]) {
            st.pop();
        } 
        if (st.empty()) res[size] = 0;
        else {
            res[size] = st.top().second - size;
        }
        st.push(std::pair<Temperature_t, Index_t >{ T[size], size });
        --size;
    }
    return res;
}

int main() {
    std::vector<int> temperature = { 73, 74, 75, 71, 69, 72, 76, 73 };
    std::vector<int> res = dailyTemperatures(temperature);
    for (const auto& val : res) {
        std::cout << val << " ";
    }
    std::cout << "\n";
    return 0;
}

