class Solution {
public:

    string encode(vector<string>& strs) {
        string ret = "";
        for (auto& i : strs) ret += to_string(i.size()) + "|" + i;
        return ret;
    }

    vector<string> decode(string s) {
        vector<string> ret;
        int i = 0;
        while (i < s.size()) {
            string value = "";
            while (s.at(i) != '|') {
                value += s.at(i);
                ++i;
            }
            ret.push_back(s.substr(i + 1, stoi(value)));
            i += stoi(value) + 1;
        }
        return ret;
    }
};
