class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = []
        for i in tokens:
            if i == '+':
                b, a = stack.pop(), stack.pop()
                result = a + b
                stack.append(result)
            elif i == '-':
                b, a = stack.pop(), stack.pop()
                result = a - b
                stack.append(result)
            elif i == '*':
                b, a = stack.pop(), stack.pop()
                result = a * b
                stack.append(result)
            elif i == '/':
                b, a = stack.pop(), stack.pop()
                result = int(a / b)
                stack.append(result)
            else:
                stack.append(int(i))
        return stack[-1]