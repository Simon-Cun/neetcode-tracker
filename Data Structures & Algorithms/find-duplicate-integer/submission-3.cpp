class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int bitmask = 0;
        for (auto& i : nums) {
            if (((1 << i) & bitmask) != 0) {
                return i;
            } else {
                bitmask |= (1 << i);
            }
        }
        return -1;
    }
};
