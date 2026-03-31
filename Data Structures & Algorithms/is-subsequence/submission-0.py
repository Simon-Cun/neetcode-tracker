class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        n, m = len(s), len(t)
        l = 0
        for r in range(m):
            if l == n:
                break
            elif s[l] == t[r]:
                l += 1
        return l == n