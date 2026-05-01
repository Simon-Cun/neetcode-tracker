class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> hashT;
        for (auto& i : t) ++hashT[i];
        
        int have = 0;
        int l = 0;
        string ret;
        unordered_map<char, int> hashS;
        for (int r = 0; r < s.size(); ++r) {
            if (hashS[s.at(r)] < hashT[s.at(r)]) {
                    ++have;
            }
            if (hashT.contains(s.at(r))) ++hashS[s.at(r)];
            while (have == t.size()) {
                while (!hashT.contains(s.at(l))) {
                    ++l;
                }
                if (ret == "" or ret.size() > r - l + 1) ret = s.substr(l, r - l + 1);

                if (hashS[s.at(l)] == hashT[s.at(l)]) {
                    --have;
                }
                --hashS[s.at(l)];
                ++l;
            }
        }
        return ret;
    }
};
