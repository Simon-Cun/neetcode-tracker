#include <vector>
#include <utility>
class Solution {
public:
    int maxArea(vector<int>& heights) {
        int res = 0;
        int l = 0, r = heights.size() - 1;
        while (l < r) {
            int leftHeight = heights.at(l), rightHeight = heights.at(r);
            res = max(res, min(leftHeight, rightHeight) * (r - l));
            if (leftHeight < rightHeight) {
                ++l;
            } else {
                --r;
            }
        }
        return res;
    }
};
