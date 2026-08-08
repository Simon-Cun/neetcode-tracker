class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hash;
        for (auto& i : nums) hash[i]++;
        vector<vector<int>> buckets(nums.size() + 1);
        for (auto& i : hash) buckets.at(i.second).push_back(i.first);
        vector<int> ret;
        for (int i = buckets.size() - 1; i >= 0; --i) {
            for (int j = buckets.at(i).size() - 1; j >= 0; --j) {
                if (ret.size() == k) return ret;
                ret.push_back(buckets.at(i).at(j));
            }
        }
        return ret;
    }
};
