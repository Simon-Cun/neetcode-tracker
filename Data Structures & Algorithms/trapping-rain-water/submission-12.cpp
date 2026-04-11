class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size() - 1, lm = height.at(l), rm = height.at(r);
        int res = 0;
        while (l < r) {
            if (lm < rm) {
                ++l;
                lm = max(lm, height.at(l));
                res += lm - height.at(l);
            } else {
                --r;
                rm = max(rm, height.at(r));
                res += rm - height.at(r);
            }
        }
        return res;
    }
};
