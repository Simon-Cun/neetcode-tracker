class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False

        n = len(s)

        x = [0] * 26
        y = [0] * 26

        for i, j in zip(s, t):
            x[ord(i) - ord('a')] += 1
            y[ord(j) - ord('a')] += 1

        return x == y