#include <unordered_set>
class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_set<int> hashMap;
        for (int i = 0; i < nums.size(); ++i) {
            if (hashMap.contains(nums.at(i))) {
                return true;
            }
            hashMap.insert(nums[i]);
        }
        return false;
    }
};