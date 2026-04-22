class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freqMap;
        for (auto& i : nums) ++freqMap[i];
        vector<vector<int>> buckets(nums.size() + 1, vector<int>(0, k));
        for (auto& i : freqMap) {
            buckets.at(i.second).push_back(i.first);
        }
        vector<int> ret;
        for (int i = buckets.size() - 1; i >= 0; --i) {
            for (int j = 0; j < buckets.at(i).size(); ++j) {
                if (ret.size() == k) break;
                ret.push_back(buckets.at(i).at(j));
            }
        }
        return ret;
    }
};
