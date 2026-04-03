#include <unordered_map>
class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_map<int, int> hashMap;
        for (int i = 0; i < nums.size(); ++i) {
            if (hashMap.contains(nums.at(i))) {
                return true;
            }
            hashMap[nums[i]] = 0;
        }
        return false;
    }
};