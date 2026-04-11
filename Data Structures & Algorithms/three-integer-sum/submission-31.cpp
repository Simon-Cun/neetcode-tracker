#include <vector>
#include <algorithm>
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for (int i = 0; i < nums.size(); ++i) {
            if (i > 0 and nums.at(i) == nums.at(i - 1)) {
                continue;
            }
            int l = i + 1, r = nums.size() - 1;
            while (l < r) {
                int s = nums.at(i) + nums.at(l) + nums.at(r);
                if (s == 0) {
                    res.push_back({nums.at(i), nums.at(l), nums.at(r)});
                    ++l;
                    --r;
                    while (l < r && nums.at(l) == nums.at(l - 1)) {
                        ++l;
                    }
                    while (l < r && nums.at(r) == nums.at(r + 1)) {
                        --r;
                    }
                } else if (s < 0) {
                    ++l;
                } else {
                    --r;
                }
            }
        }
        return res;
    }
};
