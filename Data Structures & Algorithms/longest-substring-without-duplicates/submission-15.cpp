class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int ret = 0;
        unordered_set<char> hashMap;
        for (int r = 0; r < s.size(); ++r) {
            while (hashMap.contains(s.at(r))) {
                hashMap.erase(s.at(l));
                ++l;
            }
            hashMap.insert(s.at(r));
            ret = max(ret, r - l + 1);
        }
        return ret;
    }
};
