#include <vector>
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> s1Chars(26, 0);
        for (const auto& i : s1) {
            ++s1Chars.at(i - 'a');
        }
        for (auto & i : s1Chars) cout << i << ", ";
            cout << endl;
        int l = 0;
        vector<int> s2Chars(26, 0);
        for (int r = 0; r < s2.size(); ++r) {
            ++s2Chars.at(s2.at(r) - 'a');
            if (r - l == s1.size()) {
                --s2Chars.at(s2.at(l) - 'a');
                ++l;
            }
            if (s2Chars == s1Chars) {
                return true;
            }
            for (auto & i : s2Chars) cout << i << ", ";
            cout << endl;
        }
        return false;
    }
};
