class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            cout << m << endl;
            if (nums.at(l) <= nums.at(m)) {
                if (nums.at(m) == target) {
                    return m;
                } else if (nums.at(l) <= target && target < nums.at(m)) {
                    r = m - 1;
                } else {
                    l = m + 1;
                }
            } else {
                if (nums.at(m) == target) {
                    return m;
                } else if (nums.at(m) < target && target <= nums.at(r)) {
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            }
        }
        return -1;
    }
};
