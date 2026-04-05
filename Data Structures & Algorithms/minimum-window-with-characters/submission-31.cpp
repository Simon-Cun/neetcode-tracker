#include <unordered_map>
#include <string>
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> tFreq;
        for (auto& i : t) {
            ++tFreq[i];
        }

        int have = 0;
        int l = 0;
        string res = "";
        unordered_map<char, int> sFreq;
        for (int r = 0; r < s.size(); ++r) {
            if (tFreq.contains(s[r])) {
                if (sFreq[s[r]] < tFreq[s[r]]) {
                    ++have;
                }
                ++sFreq[s[r]];
            }
            
            if (have == t.size()) {
                while (have == t.size()) {
                    if (res.empty() || res.size() > (r - l + 1)) {
                        res = s.substr(l, r - l + 1);
                    }
                    if (tFreq.contains(s[l])) {
                        if (sFreq[s[l]] <= tFreq[s[l]]) {
                            --have;
                        }
                        --sFreq[s[l]];
                    }
                    ++l;
                }
            }
        }
        return res;
    }
};