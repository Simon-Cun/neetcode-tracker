class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0, r = heights.size() - 1;
        int ret = 0;
        while (l < r) {
            int area = min(heights.at(l), heights.at(r)) * (r - l);
            cout << area << endl;
            ret = max(ret, area);
            if (heights.at(l) < heights.at(r)) {
                ++l;
            } else {
                --r;
            }
        }
        return ret;
    }
};
