#include <unordered_map>
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashMap;
        for (int i = 0; i < nums.size(); ++i) {
            int diff = target - nums.at(i);
            if (hashMap.contains(diff)) {
                return {hashMap[diff], i};
            }
            hashMap[nums.at(i)] = i;
        }
        return {-1, -1};
    }
};
