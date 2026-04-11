#include <unordered_set>
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> hashSet;
        int res = 0;
        int l = 0;
        for (int r = 0; r < s.size(); ++r) {
            
            if (hashSet.contains(s.at(r))) {
                if (s.at(l) == s.at(r)) {
                    hashSet.erase(s.at(l));
                    ++l;
                } else {
                    hashSet.clear();
                    l = r;
                }
            }
            hashSet.insert(s.at(r));
            res = max(res, r - l + 1);
        }
        return res;
    }
};
