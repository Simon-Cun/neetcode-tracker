class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for (auto& i : nums) s.insert(i);
        int ret = 0;
        for (auto&i : s) {
            if (s.contains(i - 1)) continue;
            int curr = i;
            int count = 1;
            while (s.contains(curr + 1)) {
                ++count;
                ++curr;
            }
            ret = max(ret, count);
        }
        return ret;
    }
};
