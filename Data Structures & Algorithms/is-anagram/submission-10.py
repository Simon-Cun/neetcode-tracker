class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        characters_s = [0] * 26
        characters_t = [0] * 26

        for i in s:
            characters_s[ord(i) - ord('a')] += 1
        for i in t:
            characters_t[ord(i) - ord('a')] += 1
        
        return characters_s == characters_t