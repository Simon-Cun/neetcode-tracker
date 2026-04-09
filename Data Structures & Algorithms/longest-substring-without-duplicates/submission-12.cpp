#include <unordered_map>
#include <string>
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int res = 0;
        unordered_map<char, int> hashMap;
        for (int i = 0; i < s.size(); ++i) {
            ++hashMap[s[i]];
            if (hashMap[s[l]] > 1) {
                --hashMap[s[l]];
                ++l;
            } else if (hashMap[s[i]] > 1) {
                l = i;
                hashMap.clear();
                hashMap[s[i]] = 1;
            }
            res = max(res, i - l + 1);
        }
        return res;
    }
};