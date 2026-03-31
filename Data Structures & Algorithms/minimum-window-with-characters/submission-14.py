class Solution:
    def minWindow(self, s: str, t: str) -> str:
        n, m = len(s), len(t)
        res = ""

        d_t = {}
        for i in t:
            d_t[i] = d_t.get(i, 0) + 1

        d_s = {}
        l = 0
        have = 0
        for r, char in enumerate(s):
            if char in d_t:
                d_s[char] = d_s.get(char, 0) + 1
                if d_s[char] <= d_t[char]:
                    have += 1
            while have == m:
                while l < r and s[l] not in d_t:
                    l += 1
                while l < r and d_s[s[l]] - 1 > d_t[s[l]]:
                    d_s[s[l]] -= 1
                    l += 1
                if res == "":
                    res = s[l:r + 1]
                elif len(res) > len(s[l:r + 1]):
                    res = s[l:r + 1]
                
                d_s[s[l]] -= 1
                if d_s[s[l]] != d_t[s[l]]:
                    have -= 1
                l += 1
                while l < r and s[l] not in d_t:
                    l += 1
        return res

            
            

            

