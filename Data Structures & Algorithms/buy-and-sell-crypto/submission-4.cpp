class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ret = 0;
        int l = 0;
        for (int r = 0; r < prices.size(); ++r) {
            ret = max(ret, prices.at(r) - prices.at(l));
            if (prices.at(l) > prices.at(r)) l = r;
        }
        return ret;
    }
};
