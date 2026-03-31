class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False

        s_1 = [0] * 26
        s_2 = [0] * 26

        for i, j in zip(s, t):
            s_1[ord(i) - ord('a')] += 1
            s_2[ord(j) - ord('a')] += 1

        return s_1 == s_2