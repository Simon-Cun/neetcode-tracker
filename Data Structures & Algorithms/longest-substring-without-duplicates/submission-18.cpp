class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> hash;
        int l = 0;
        int ret = 0;
        for (int r = 0; r < s.size(); ++r) {
            while (hash.find(s.at(r)) != hash.end()) {
                hash.erase(s.at(l));
                ++l;
            }
            ret = max(ret, r - l + 1);
            hash.insert(s.at(r));
        }
        return ret;
    }
};
