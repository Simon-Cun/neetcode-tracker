class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (auto& i : nums) freq[i]++;
        vector<vector<int>> buckets(nums.size() + 1);
        for (auto& i : freq) buckets.at(i.second).push_back(i.first);
        reverse(buckets.begin(), buckets.end());
        vector<int> ret;
        for (auto& i : buckets) {
            for (auto& j : i) {
                if (ret.size() == k) return ret;
                else ret.push_back(j);
            }
        }
        return ret;
    }
};
