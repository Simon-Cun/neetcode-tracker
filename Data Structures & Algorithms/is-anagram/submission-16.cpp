#include <vector>
class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<char> sChars(26, 0);
        for (auto& i : s) {
            ++sChars.at(i - 'a');
        }
        vector<char> tChars(26, 0);
        for (auto& i : t) {
            ++tChars.at(i - 'a');
        }
        return tChars == sChars;
    }
};
