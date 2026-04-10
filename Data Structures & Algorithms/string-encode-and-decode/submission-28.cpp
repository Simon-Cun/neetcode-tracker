class Solution {
public:

    string encode(vector<string>& strs) {
        string res = "";
        for (auto& i : strs) {
            res +=  to_string(i.size()) + "|" + i;
        }
        return res;
    }

    vector<string> decode(string s) {
        string currNum = "";
        vector<string> res;
        int i = 0;
        while (i < s.size()) {
            if (s.at(i) != '|') {
                currNum += s.at(i);
                ++i;
            } else {

                int value = stoi(currNum);
                currNum = "";
                res.push_back(s.substr(i + 1, value));
                i += value + 1;
            }
        }
        return res;
    }
};
