class Solution:
    def isPalindrome(self, s: str) -> bool:
        new_string = ""
        for i in s:
            if i.isalnum():
                new_string += i.lower()
        return new_string[::-1] == new_string