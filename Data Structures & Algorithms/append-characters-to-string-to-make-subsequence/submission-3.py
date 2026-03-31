class Solution:
    def appendCharacters(self, s: str, t: str) -> int:
        n, m = len(s), len(t)
        l = 0
        for r in range(n):
            if l == m:
                return m - l
            elif t[l] == s[r]:
                l += 1
        return m - l