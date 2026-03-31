class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        dictionary = {}
        for j in s:
            dictionary[j] = dictionary.get(j, 0) + 1
        dictionary2 = {}
        for j in t:
            dictionary2[j] = dictionary2.get(j, 0) + 1
        if dictionary == dictionary2:
            return True
        return False