#include <algorithm>
class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0, r = heights.size() - 1;
        int maxArea = 0;
        while (l < r) {
            int currArea = min(heights.at(l), heights.at(r)) * (r - l);
            maxArea = max(maxArea, currArea);
            if (heights.at(l) < heights.at(r)) {
                ++l;
            } else {
                --r;
            }
        }
        return maxArea;
    }
};
