class Solution:
    def isValid(self, s: str) -> bool:
        brackets = {'(' : ')', '{' : '}', '[' : ']'}
        stack = []
        for i in s:
            if i in brackets:
                stack.append(i)
            elif stack and brackets.get(stack[-1]) == i:
                stack.pop()
            else:
                return False
        return not stack