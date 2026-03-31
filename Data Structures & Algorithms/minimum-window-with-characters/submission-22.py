class Solution:
    def minWindow(self, s: str, t: str) -> str:
        n, m = len(s), len(t)
        res = ""

        d_t = {}
        for i in t:
            d_t[i] = d_t.get(i, 0) + 1
        d_s = {}
        have = 0
        l = 0
        for r in range(n):
            if s[r] in d_t:
                d_s[s[r]] = d_s.get(s[r], 0) + 1
                if d_t[s[r]] >= d_s[s[r]]:
                    have += 1
            
            while have == m:
                if res == "" or len(res) > len(s[l : r + 1]):
                    res = s[l : r + 1]
                if s[l] in d_s:
                    d_s[s[l]] -= 1
                    if s[l] in d_t and d_t[s[l]] > d_s[s[l]]:
                        have -= 1
                l += 1

        return res
            

            

