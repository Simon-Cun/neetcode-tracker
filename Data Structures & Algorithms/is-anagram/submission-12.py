class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        chars_s = [0] * 26
        chars_t = [0] * 26
        
        if len(s) != len(t):
            return False

        for i in s:
            chars_s[ord(i) - ord('a')] += 1
        for i in t:
            chars_t[ord(i) - ord('a')] += 1

        return chars_s == chars_t