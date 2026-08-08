class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        vector<int> charMap1(26, 0);
        vector<int> charMap2(26, 0);
        for (int i = 0; i < s.size(); ++i) {
            ++charMap1.at(s.at(i) - 'a');
            ++charMap2.at(t.at(i) - 'a');
        }
        return charMap1 == charMap2;
    }
};
