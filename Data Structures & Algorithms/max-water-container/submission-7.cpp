class Solution {
public:
    int maxArea(vector<int>& heights) {
        int ret = 0;
        int l = 0, r = heights.size() - 1;
        while (l < r) {
            int minHeight = min(heights.at(l), heights.at(r));
            ret = max(ret, minHeight * (r - l));
            if (heights.at(l) < heights.at(r)) ++l;
            else --r;
        }
        return ret;
    }
};
