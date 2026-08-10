class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int lMax = height.at(l), rMax = height.at(r);
        int ret = 0;
        while (l < r) {
            if (height.at(l) < height.at(r)) {
                ++l;
                lMax = max(lMax, height.at(l));
                ret += lMax - height.at(l);
            } else {
                --r;
                rMax = max(rMax, height.at(r));
                ret += rMax - height.at(r);
            }
        }
        return ret;
    }
};
