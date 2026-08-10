class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0;
        int ret = 0;
        unordered_map<char, int> hash;
        char m = s.at(0);
        for (int r = 0; r < s.size(); ++r) {
            ++hash[s.at(r)];
            if (hash[s.at(r)] >= hash[m]) m = s.at(r);
            if (r - l + 1 - hash[m] > k) {
                --hash[s.at(l)];
                ++l;
            }
            ret = max(ret, r - l + 1);
        }
        return ret;
    }
};
