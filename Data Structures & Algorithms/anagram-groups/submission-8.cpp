#include <vector>
#include <string>
#include <unordered_map>
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> res;
        for (int i = 0; i < strs.size(); ++i) {
            vector<int> charMap(26, 0);
            for (int j = 0; j < strs[i].size(); ++j) {
                charMap.at((int)strs[i][j] - (int)'a') += 1;
            }
            string key = "";
            for (int j = 0; j < 26; ++j) {
                key += to_string(charMap[j]) + "|";
            }
            res[key].push_back(strs[i]);
        }

        vector<vector<string>> grouped_anagrams;
        for (auto&pair : res) {
            grouped_anagrams.push_back(pair.second);
        }
        
        return grouped_anagrams;
    }
};
