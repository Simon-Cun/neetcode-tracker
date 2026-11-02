class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minBuy = prices.at(0);
        int ret = 0;
        for (auto& i : prices) {
            minBuy = min(minBuy, i);
            ret = max(ret, i - minBuy);
        }
        return ret;
    }
};
