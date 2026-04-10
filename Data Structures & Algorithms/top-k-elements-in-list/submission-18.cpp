#include <unordered_map>
#include <vector>
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freqMap;
        for (auto& i : nums) ++freqMap[i];

        vector<vector<int>> buckets(nums.size() + 1);
        for (auto& i : freqMap) {
            buckets.at(i.second).push_back(i.first);
        }

        reverse(buckets.begin(), buckets.end());
        vector<int> res;
        for (auto& i : buckets) {
            for (auto& j : i) {
                if (res.size() != k) {
                    res.push_back(j);
                }
            }
        }
        return res;
    }
};
