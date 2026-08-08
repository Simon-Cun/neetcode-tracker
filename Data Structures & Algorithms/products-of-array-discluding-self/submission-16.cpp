class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ret(nums.size(), 1);
        int prefix = 1;
        int postfix = 1;
        for (int i = 0; i < nums.size(); ++i) {
            ret.at(i) *= prefix;
            ret.at(nums.size() - i - 1) *= postfix;
            prefix *= nums.at(i);
            postfix *= nums.at(nums.size() - i - 1);
        }
        return ret;
    }
};
