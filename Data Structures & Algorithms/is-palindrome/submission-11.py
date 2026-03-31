class Solution:
    def isPalindrome(self, s: str) -> bool:
        string = ""
        for i in s:
            if i.isdigit() or i.isalpha():
                string += i.lower()
        return string == string[::-1]