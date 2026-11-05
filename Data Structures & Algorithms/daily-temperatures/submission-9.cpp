class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        vector<int> ret(temperatures.size(), 0);
        for (int i = 0; i < temperatures.size(); ++i) {
            while (!st.empty() && temperatures.at(st.top()) < temperatures.at(i)) {
                int idx = st.top();
                st.pop();
                ret.at(idx) = i - idx;
            }
            st.push(i);
        }
        return ret;
    }
};
