from typing import List

class Solution:
    def encode(self, strs: List[str]) -> str:
        # Each string is prefixed with its length and a '#'
        return ''.join(f"{len(s)}#{s}" for s in strs)

    def decode(self, s: str) -> List[str]:
        res = []
        i = 0
        while i < len(s):
            # Find the separator to get the length prefix
            j = s.find('#', i)
            length = int(s[i:j])            # Length of the next string
            i = j + 1                       # Move past the '#'
            res.append(s[i:i + length])     # Grab the actual string
            i += length                     # Move to the next string
        return res
