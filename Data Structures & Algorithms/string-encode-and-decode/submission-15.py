class Solution:

    def encode(self, strs: List[str]) -> str:
        res = ""
        for i, n in enumerate(strs):
            res += n + "`"
        return res
    def decode(self, s: str) -> List[str]:
        l = []
        string = ""
        for i in s:
            if i != "`":
                string += i
            elif i == "`":
                l.append(string)
                string = ""
        return l