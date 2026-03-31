class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        s = s.strip()
        print(s)
        return len(s.split(' ')[-1])