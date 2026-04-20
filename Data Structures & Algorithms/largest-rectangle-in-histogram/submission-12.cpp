class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;
        stack<pair<int, int>> st; // pair<index, height>
        for (int i = 0; i < heights.size(); ++i) {
            int start = i;
            while (!st.empty() && st.top().second > heights.at(i)) {
                int index = st.top().first, height = st.top().second;
                st.pop();
                maxArea = max(maxArea, height * (i - index));
                start = index;
            }
            st.push({start, heights.at(i)});
        }
        while (!st.empty()) {
            maxArea = max(maxArea, st.top().second * ((int)heights.size() - st.top().first));
            st.pop();
        }
        return maxArea;
    }
};
