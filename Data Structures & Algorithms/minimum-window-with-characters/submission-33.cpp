#include <vector>
#include <unordered_map>
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> need;
        for (const auto& i : t) {
            ++need[i];
        }

        int l = 0;
        int have = 0;
        string res = "";
        unordered_map<char, int> seen;
        for (int r = 0; r < s.size(); ++r) {
            if (need.contains(s.at(r))) {
                if (seen[s.at(r)] < need.at(s.at(r))) {
                    ++have;
                }
                ++seen[s.at(r)];
            }
            while (have == t.size()) {
               if (res.empty() || res.size() > (r - l + 1)) {
                res = s.substr(l, r - l + 1);
               }
               if (seen.contains(s.at(l))) {
                if (seen.at(s.at(l)) == need.at(s.at(l))) {
                    --have;
                }
                --seen[s.at(l)];
               }
               ++l;
            }
        }
        return res;

    }
};
