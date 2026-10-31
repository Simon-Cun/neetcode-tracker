class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;
        for (int i = 0; i < nums.size(); ++i) {
            int diff = target - nums.at(i);
            if (hash.find(diff) != hash.end()) return {hash[diff], i};
            else hash[nums.at(i)] = i;
        }
        return {};
    }
};
