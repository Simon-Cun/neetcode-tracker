class Solution {
public:

    string encode(vector<string>& strs) {
        string ret = "";
        for (auto& i : strs) ret += to_string(i.size()) + "|" + i;
        return ret;
    }

    vector<string> decode(string s) {
        vector<string> ret;
        string num = "";
        for (int i = 0; i < s.size(); ++i) {
            if (s.at(i) != '|') num += s.at(i);
            else {
                ret.push_back(s.substr(i + 1, stoi(num)));
                i += stoi(num);
                num = "";
            }
        }
        return ret;
    }
};
