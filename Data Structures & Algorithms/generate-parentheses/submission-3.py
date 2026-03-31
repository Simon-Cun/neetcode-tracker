class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        stack = []
        res = []
        def b(o, c):
            if o == c == n:
                res.append("".join(stack))
                return
            if o < n:
                stack.append('(')
                b(o + 1, c)
                stack.pop()
            if c < o:
                stack.append(')')
                b(o, c + 1)
                stack.pop()
        b(0, 0)
        return res
