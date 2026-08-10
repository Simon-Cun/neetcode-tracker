class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> charMapS1(26, 0);
        for (auto& i : s1) ++charMapS1.at(i - 'a');
        vector<int> charMapS2(26, 0);
        int l = 0;
        for (int i = 0; i < s2.size(); ++i) {
            for (auto& j : charMapS2) cout << j;
            cout << endl;
            
            if (i < s1.size()) {
                ++charMapS2.at(s2.at(i) - 'a');
            } else {
                --charMapS2.at(s2.at(l) - 'a');
                ++l;
                ++charMapS2.at(s2.at(i) - 'a');
            }
            if (charMapS1 == charMapS2) return true;
        }
        return false;
    }
};
