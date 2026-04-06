#include <stack>
#include <vector>
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        vector<int> res(temperatures.size(), 0);
        for (int i = temperatures.size() - 1; i >= 0; --i) {
            while (true) {
                if (st.empty()) {
                    res.at(i) = 0;
                    st.push(i);
                    break;
                }
                else if (temperatures[st.top()] > temperatures[i])
                {
                    res.at(i) = st.top() - i;
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
        return res;
    }
};
