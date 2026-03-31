class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        minimum = prices[0]
        profit = 0
        for i in prices:
            minimum = min(i, minimum)
            profit = max(profit, i - minimum)
        return profit