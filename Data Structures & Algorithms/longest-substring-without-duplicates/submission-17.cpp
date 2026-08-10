class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> hash;
        int l = 0;
        int ret = 0;
        for (int r = 0; r < s.size(); ++r) {
            ++hash[s.at(r)];
            while (hash[s.at(r)] > 1) {
                --hash[s.at(l)];
                ++l;
            }
            ret = max(ret, r - l + 1);
        }
        return ret;
    }
};
