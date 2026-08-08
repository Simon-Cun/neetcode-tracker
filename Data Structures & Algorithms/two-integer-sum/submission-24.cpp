class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;
        for (int i = 0; i < nums.size(); ++i) {
            int diff = target - nums.at(i);
            if (hash.contains(diff)) return {hash.at(diff), i};
            hash[nums.at(i)] = i;
        }
        return {};
    }
};
