class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        l = prices[0]
        profit = 0
        for r in prices:
            if r - l > 0:
                profit += r - l
                l = r
            l = min(l, r)
        return profit