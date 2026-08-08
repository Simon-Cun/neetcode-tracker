class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> hash;
        for (auto& i : nums) hash[i]++;
        for (auto& i : hash) if (i.second != 1) return true;
        return false;
    }
};