#include <algorithm>
#include <vector>

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for (int i = 0; i < nums.size(); ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int l = i + 1, r = nums.size() - 1;
            while (l < r) {
                int currSum = nums[i] + nums[l] + nums[r];
                if (currSum == 0) {
                    res.push_back({nums[i], nums[l], nums[r]});
                    ++l;
                    --r;
                    while (l < r and nums[l] == nums[l - 1]) {
                        ++l;
                    }
                    while (l < r and nums[r] == nums[r + 1]) {
                        --r;
                    }
                } else if (currSum < 0) {
                    ++l;
                } else {
                    --r;
                }
            }
            
        }
        return res;
    }
};
