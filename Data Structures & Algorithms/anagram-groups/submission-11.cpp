#include <vector>
#include <unordered_map>
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hashMap;
        for (auto& i : strs) {
            vector<int> chars(26, 0);
            for (auto& j : i) {
                ++chars.at(j - 'a');
            }
            string key = "";
            for (int j = 0; j < 26; ++j) {
                key += to_string(chars[j]) + "|";
            }
            hashMap[key].push_back(i);
        }
        vector<vector<string>> res;
        for (auto& i : hashMap) {
            res.push_back(i.second);
        }
        return res;
        
    }
};
