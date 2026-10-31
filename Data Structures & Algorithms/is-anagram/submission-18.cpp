class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> charMapS(26, 0);
        for (auto& i : s) charMapS.at(i - 'a')++;
        vector<int> charMapT(26, 0);
        for (auto& i : t) charMapT.at(i - 'a')++;
        return charMapS == charMapT;
    }
};
