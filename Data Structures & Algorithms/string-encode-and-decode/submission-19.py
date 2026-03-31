class Solution:

    def encode(self, strs: List[str]) -> str:
        new_string = ""
        for i in strs:
            new_string += i + '~'
        return new_string
    def decode(self, s: str) -> List[str]:
        res = []
        string = ""
        for i in s:
            if i != '~':
                string += i
            else:
                res.append(string)
                string = ""
        return res