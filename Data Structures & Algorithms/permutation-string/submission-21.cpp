class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> charMap1(26, 0);
        vector<int> charMap2(26, 0);
        if (s1.size() > s2.size()) return false;
        for (int i = 0; i < s1.size(); ++i) {
            ++charMap1.at(s1.at(i) - 'a');
            ++charMap2.at(s2.at(i) - 'a');
        }
        if (charMap1 == charMap2) return true;
        int l = 0;
        for (int r = s1.size(); r < s2.size(); ++r) {
            for (auto&i : charMap1) cout << i;
            cout << endl;
            for (auto&i : charMap2) cout << i;
            cout << endl;
            if (charMap1 == charMap2) return true;
            ++charMap2.at(s2.at(r) - 'a');
            --charMap2.at(s2.at(l) - 'a');
            ++l;
            if (charMap1 == charMap2) return true;
        }
        return false;
    }
};
