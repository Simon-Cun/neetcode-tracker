class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        dictionary1 = {}
        for i in range(len(s)):
            dictionary1[s[i]] = dictionary1.get(s[i], 0) + 1
        dictionary2 = {}
        for i in range(len(t)):
            dictionary2[t[i]] = dictionary2.get(t[i], 0) + 1
        return dictionary1 == dictionary2