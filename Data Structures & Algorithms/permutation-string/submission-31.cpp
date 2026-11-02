class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> charMap1(26, 0);
        for (auto& i : s1) charMap1.at(i - 'a')++;
        vector<int> charMap2(26, 0);
        int l = 0;
        for (int r = 0; r < s2.size(); ++r) {
            for (auto& i : charMap1) cout << i << ' ';
            cout << endl;
            for (auto& i : charMap2) cout << i << ' ';
            cout << endl;
            cout << endl;
            while (r - l + 1 > s1.size()) {
                charMap2.at(s2.at(l) - 'a')--;
                ++l;
            }
            charMap2.at(s2.at(r) - 'a')++;
            if (charMap1 == charMap2) return true;
        }
        return false;
    }
};
