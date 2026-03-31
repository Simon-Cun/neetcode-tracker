from functools import lru_cache
class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        @lru_cache(None)
        def dp(i):
            if i >= len(cost):
                return 0
            return cost[i] + min(dp(i + 1), dp(i + 2))
        return min(dp(0), dp(1))