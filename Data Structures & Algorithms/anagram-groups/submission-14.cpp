class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hash;
        for (auto& i : strs) {
            vector<int> charMap(26, 0);
            for (auto& j : i) {
                ++charMap.at(j - 'a');
            }
            string strHash = "";
            for (auto& j : charMap) {
                strHash += j + '|';
            }
            hash[strHash].push_back(i);
        }
        vector<vector<string>> ret;
        for (auto& i : hash) {
            ret.push_back(i.second);
        }
        return ret;
    }
};
