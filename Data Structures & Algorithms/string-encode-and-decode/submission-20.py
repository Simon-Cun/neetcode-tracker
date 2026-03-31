class Solution:

    def encode(self, strs: List[str]) -> str:
        res = ""

        for i in strs:
            res += i + '~'

        return res
    def decode(self, s: str) -> List[str]:
        res = []

        string = ""

        for i in s:
            if i == '~':
                res.append(string)
                string = ""
            else:
                string += i

        return res

            
