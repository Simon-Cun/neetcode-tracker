#include <unordered_map>
class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> hashMap;
        int l = 0;
        int res = 0;
        int maxFreq = 0;
        for (int r = 0; r < s.size(); ++r) {
            if (hashMap.contains(s[r])) {
                hashMap[s[r]] += 1;
            } else {
                hashMap[s[r]] = 1;
            }
            maxFreq = max(maxFreq, hashMap[s[r]]);
            
            while ((r - l) - maxFreq >= k) {
                --hashMap[s[l]];
                ++l;
            }
            res = max(res, r - l + 1);
        }
        return res;
    }
};
