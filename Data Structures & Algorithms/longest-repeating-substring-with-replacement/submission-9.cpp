class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> freqMap;
        int ret = 0;
        int l = 0;
        int largest = 0;
        for (int r = 0; r < s.size(); ++r) {
            ++freqMap[s.at(r)];
            largest = max(largest, freqMap[s[r]]);
            while ((r - l + 1) - largest > k) {
                --freqMap[s.at(l)];
                ++l;
            }
            ret = max(ret, r - l + 1);
        }
        return ret;
    }
};
