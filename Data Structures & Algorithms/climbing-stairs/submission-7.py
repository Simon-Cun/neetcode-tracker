from functools import lru_cache

class Solution:
    def climbStairs(self, n: int) -> int:
        @lru_cache(None)
        def dfs(k: int) -> int:
            if k <= 1:
                return 1
            return dfs(k - 1) + dfs(k - 2)

        return dfs(n)
