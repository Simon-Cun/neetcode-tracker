#include <vector>
#include <unordered_map>
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freqMap;
        for (int i = 0; i < nums.size(); ++i) {
            if (freqMap.contains(nums[i])) {
                freqMap[nums[i]] += 1;
            } else {
                freqMap[nums[i]] = 1;
            }
        }
        vector<vector<int>> buckets(nums.size() + 1, vector<int>(0));
        for (auto&pair : freqMap) {
            buckets.at(pair.second).push_back(pair.first);
        }
        
        vector<int> res;
        for (int i = buckets.size() - 1; i >= 0; --i) {
            for (int j = buckets.at(i).size() - 1; j >= 0; --j) {
                if (k == 0) {
                    break;
                }
                res.push_back(buckets[i][j]);
                k--;
            }
            
        }
        return res;

    }
};
