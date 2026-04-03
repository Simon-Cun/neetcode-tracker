#include <unordered_map>
#include <string>
#include <vector>
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        vector<int> arrS(26, 0);
        vector<int> arrT(26, 0);
        for (int i = 0; i < s.size(); ++i) {
            arrS.at((int)s[i] - (int)'a') += 1;
            arrT.at((int)t[i]  - (int)'a') += 1;
        }

        return arrS == arrT;
    }
};
