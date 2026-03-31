class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        index = 0
        length = 0
        mySet = set()
        for i, k in enumerate(s):
            while k in mySet:
                mySet.remove(s[index])
                index += 1
            else:
                mySet.add(k)
            if length < i - index + 1:
                length = i - index + 1
            
        
        return length
            