#include <vector>
#include <string>
#include <iostream>

class Solution {
public:

    string encode(vector<string>& strs) {
        string ret = "";
        for (auto& i : strs) {
            ret += to_string(i.size()) + "|" + i;
        }
        return ret;
    }

    vector<string> decode(string s) {
        vector<string> ret;
        int i = 0;
        string currSize = "";
        while (i < s.size()) {
            if (s.at(i) != '|') {
                currSize += s[i];
                ++i;
            } else {
                int value = stoi(currSize);
                currSize = "";
                ret.push_back(s.substr(i + 1, value));
                i += value + 1;
            }
        }
        return ret;
    }
};
