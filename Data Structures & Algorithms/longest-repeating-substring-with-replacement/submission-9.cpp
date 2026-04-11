#include <unordered_map>
class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0;
        int res = 0;
        int maxFreq = 0;
        unordered_map<char, int> freqMap;
        for (int r = 0; r < s.size(); ++r) {
            ++freqMap[s[r]];
            maxFreq = max(maxFreq, freqMap[s[r]]);
            while ((r - l + 1) - maxFreq > k) {
                --freqMap[s.at(l)];
                ++l;
            }
            res = max(res, r - l + 1);
        }
        return res;
    }
};
