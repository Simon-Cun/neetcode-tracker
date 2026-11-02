class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int lm = height.at(l), rm = height.at(r);
        int ret = 0;
        while (l < r) {
            if (lm < rm) {
                ++l;
                lm = max(lm, height.at(l));
                ret += lm - height.at(l);
            } else {
                --r;
                rm = max(rm, height.at(r));
                ret += rm - height.at(r);
            }
        }
        return ret;
    }
};
