#include <string>
class Solution {
public:

    string encode(vector<string>& strs) {
        string encodedString = "";
        for (int i = 0; i < strs.size(); ++i) {
            encodedString +=  to_string(strs[i].size()) + "|" + strs[i];
        }
        cout << encodedString;
        return encodedString;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int i = 0;
        int currLength = 0;
        while (i < s.size()) {
            string str = "";
            while (s[i] != '|') {
                str += s[i];
                ++i;
            }
            ++i;
            currLength = stoi(str);
            res.push_back(s.substr(i, currLength));
            i += currLength;
            
        }
        return res;
    }
};