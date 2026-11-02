class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> hashT;
        for (auto& i : t) hashT[i]++;
        int l = 0;
        int have = 0;
        unordered_map<char, int> hashS;
        int retL = -1, retR = -1;
        for (int r = 0; r < s.size(); ++r) {
            if (hashT.find(s.at(r)) != hashT.end() && hashS[s.at(r)] < hashT[s.at(r)]) {
                ++have;
            }
            hashS[s.at(r)]++;
            while (have == t.size()) {
                if (retL == -1 || retR - retL + 1 > r - l + 1) {
                    retL = l;
                    retR = r;
                }
                if (hashT.find(s.at(l)) != hashT.end() && hashS[s.at(l)] <= hashT[s.at(l)]) --have;
                hashS[s.at(l)]--;
                ++l;
            }
        }
        if (retL == -1) return "";
        return s.substr(retL, retR - retL + 1);
    }
};
