class Solution {
public:
    int findMin(vector<int> &nums) {
        int ret = nums.at(0);
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            if (nums.at(l) < nums.at(r)) {
                ret = min(ret, nums.at(l));
                break;
            }
            int m = l + (r - l) / 2;
            ret = min(ret, nums.at(m));
            if (nums.at(m) >= nums.at(l)) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return ret;
    }
};
