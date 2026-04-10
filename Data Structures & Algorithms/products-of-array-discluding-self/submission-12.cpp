class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ret(nums.size(), 1);
        int prefix = 1;
        for (int i = 0; i < nums.size() - 1; ++i) {
            ret.at(i + 1) = prefix * nums.at(i);
            prefix *= nums.at(i);
        }
        int postfix = 1;
        for (int i = nums.size() - 1; i > 0; --i) {
            ret.at(i - 1) *= (postfix * nums.at(i));
            postfix *= nums.at(i);
        }

        return ret;
    }
};
