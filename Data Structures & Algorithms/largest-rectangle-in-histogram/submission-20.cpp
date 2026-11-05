class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int ret = 0;
        stack<pair<int, int>> st;
        for (int i = 0; i < n; ++i) {
            int idx = i;
            while (!st.empty() && heights.at(i) < st.top().second) {
                ret = max(ret, (i - st.top().first) * st.top().second);
                idx = st.top().first;
                st.pop();
            }
            st.push({idx, heights.at(i)});
        }
        while (!st.empty()) {
            ret = max(ret, (n - st.top().first) * st.top().second);
            st.pop();
        }

        return ret;
    }
};
