class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int lMax = height[l], rMax = height[r];
        int res = 0;
        while (l < r) {
            if (lMax < rMax) {
                ++l;
                lMax = max(lMax, height[l]);
                res += max(lMax - height[l], 0);
            } else {
                --r;
                rMax = max(rMax, height[r]);
                res += max(rMax - height[r], 0);
            }
        }
        return res;
    }
};
