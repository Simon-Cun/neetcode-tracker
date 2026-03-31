class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        minimum = prices[0]
        profit = 0

        for i in prices:
            if i < minimum:
                minimum = i
            if profit < i - minimum:
                profit = i - minimum
        
        return profit