class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> hash;
        int l = 0;
        int ret = 0;
        int maxFreq = 0;
        for (int r = 0; r < s.size(); ++r) {
            hash[s.at(r)]++;
            maxFreq = max(maxFreq, hash[s.at(r)]);
            while (r - l + 1 - maxFreq > k) {
                hash[s.at(l)]--;
                ++l;
            }
            ret = max(ret, r - l + 1);
        }
        return ret;
    }
};
