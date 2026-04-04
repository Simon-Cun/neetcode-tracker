#include <vector>
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> s1CharMap(26, 0);
        for (auto& i : s1) {
            s1CharMap.at(i - 'a') += 1;
        }

        vector<int> s2CharMap(26, 0);
        int l = 0;
        for (int r = 0; r < s2.size(); ++r) {
            s2CharMap.at(s2[r] - 'a') += 1;

            if (r + 1 > s1.size()) {
                --s2CharMap.at(s2[l] - 'a');
                l += 1;
            }
            if (s1CharMap == s2CharMap) {
                return true;
            }
        }
        return false;
    }
};