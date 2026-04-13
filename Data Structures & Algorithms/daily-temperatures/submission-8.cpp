#include <stack>
#include <vector>
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        vector<int> res(temperatures.size(), 0);
        for (int i = 0; i < temperatures.size(); ++i) {
            while (!st.empty() && temperatures.at(i) > temperatures.at(st.top())) {
                int value = st.top();
                st.pop();
                res.at(value) = i - value;
            }
            st.push(i);
        }
        return res;
    }
};
