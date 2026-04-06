#include <stack>
#include <vector>
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        vector<int> res;
        for (int i = temperatures.size() - 1; i >= 0; --i) {
            while (true) {
                if (st.empty()) {
                    res.push_back(0);
                    st.push(i);
                    break;
                }
                else if (temperatures[st.top()] > temperatures[i])
                {
                    res.push_back(st.top() - i);
                    while (!st.empty() && temperatures[st.top()] <= temperatures[i]) {
                        st.pop();
                    }
                    st.push(i);
                    break;
                }
                else
                {
                    while (!st.empty() && temperatures[st.top()] <= temperatures[i]) {
                        st.pop();
                    }
                }
            }
        }
        vector<int> returnRes;
        for (int i = res.size() - 1; i >= 0; --i) {
            returnRes.push_back(res.at(i));
        }
        return returnRes;
    }
};
