class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hashMap;
        for (int i = 0; i < strs.size(); ++i) {
            vector<int> charsMap(26, 0);
            for (auto& i : strs.at(i)) {
                charsMap.at(i - 'a') += 1;
            }
            string key = "";
            for (auto& i : charsMap) {
                key += '|' + i;
            }
            hashMap[key].push_back(strs.at(i));
        }
        vector<vector<string>> ret;
        for (auto& i : hashMap) {
            ret.push_back(i.second);
        }
        return ret;
    }
};
