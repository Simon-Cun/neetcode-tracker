#include <unordered_set>
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> values;
        for (const auto& i : nums) {
            values.insert(i);
        }
        int ret = 0;
        for (const auto& i : values) {
            if (!values.contains(i - 1)) {
                int count = 1;
                int curr = i;
                while (values.contains(curr + 1)) {
                    count += 1;
                    curr += 1;
                }
                ret = max(ret, count);
            }
        }
        return ret;
    }
};
