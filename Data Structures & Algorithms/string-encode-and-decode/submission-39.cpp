class Solution {
public:

    string encode(vector<string>& strs) {
        string ret = "";
        for (auto& i : strs) {
            ret += to_string(i.size()) + '|' + i;
        }
        return ret;
    }

    vector<string> decode(string s) {
        vector<string> ret;
        string currStrNum = "";
        for (int i = 0; i < s.size(); ++i) {
            if (s.at(i) != '|') {
                currStrNum += s.at(i);
            } else {
                ret.push_back(s.substr(i + 1, stoi(currStrNum)));
                i += stoi(currStrNum);
                currStrNum = "";
            }
        }
        return ret;
    }
};
