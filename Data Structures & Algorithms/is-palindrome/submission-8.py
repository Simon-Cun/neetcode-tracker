class Solution:
    def isPalindrome(self, s: str) -> bool:
        
        newString = ""
        for i in s:
            if i.isalpha() or i.isdigit():
                newString += i.lower()

        return newString == newString[::-1]