class Solution:

    def encode(self, strs: List[str]) -> str:
        if not strs:
            return ""
        return "`".join(strs) + '`'
    def decode(self, s: str) -> List[str]:
        res = []
        string = ""
        for i in s:
            if i != '`':
                string += i
            else:
                res.append(string)
                string = ""
        return res