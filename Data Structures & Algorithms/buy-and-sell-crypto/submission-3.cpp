#include <climits>
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int ret = 0;
        for (const auto& i : prices) {
            minPrice = min(minPrice, i);
            ret = max(ret, i - minPrice);
        }
        return ret;
    }
};
