class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        left = 0
        setN = set(list(s1))
        for i in range(len(s1), len(s2) + 1):
            num = i - len(s1)
            if sorted(s2[num:i]) == sorted(s1):
                return True
        return False
