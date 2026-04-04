#include <unordered_set>
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> content;
        for (int i = 0; i < nums.size(); ++i) {
            content.insert(nums[i]);
        }

        int res = 0;
        for(const auto& element : content) {
            if (!content.contains(element - 1)) {
                int currRes = 1;
                int current = element;
                while (content.contains(current + 1)) {
                    currRes += 1;
                    current += 1;
                }
                res = max(res, currRes);
            }
        }
        return res;
    }
};
