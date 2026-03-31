class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        symbols = {'[' : ']', '{' : '}', '(' : ')'}
        for i in s:
            if i in symbols:
                stack.append(i)
            else:
                if not stack or i != symbols[stack[-1]]:
                    return False
                stack.pop()
        return not stack
            