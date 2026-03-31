class Solution:
    def scoreOfString(self, s: str) -> int:
        res = 0
        for i in range(len(s)):
            if len(s) <= 1:
                break
            if i == 0 and len(s):
                res +=  abs(ord(s[i]) - ord(s[i + 1]))
            elif i == len(s) - 1:
                res += abs(ord(s[i]) - ord(s[i - 1]))
            else:
                res += abs(ord(s[i]) - ord(s[i - 1])) + abs(ord(s[i]) - ord(s[i + 1]))
        return res // 2