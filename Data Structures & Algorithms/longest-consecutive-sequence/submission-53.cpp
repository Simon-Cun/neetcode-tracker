class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int ret = 0;
        for (auto& i : nums) {
            if (s.find(i + 1) == s.end()) {
                int count = 1;
                int curr = i;
                while (s.find(curr - 1) != s.end()) {
                    ++count;
                    --curr;
                }
                ret = max(count, ret);
            }
        }
        return ret;
    }
};
