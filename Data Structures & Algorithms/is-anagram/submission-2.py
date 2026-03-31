class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        set1 = []
        set2 = []

        if len(s) != len(t):
            return False

        for char1, char2 in zip(s, t):
            set1.append(char1)
            set2.append(char2)
        set1.sort()
        set2.sort()
        if set1 == set2:
            return True

        return False