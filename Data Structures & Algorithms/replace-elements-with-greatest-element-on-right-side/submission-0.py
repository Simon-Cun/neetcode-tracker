class Solution:
    def replaceElements(self, arr: List[int]) -> List[int]:
        res = [-1]
        curr_max = float('-inf')
        for n in reversed(arr[1:]):
            curr_max = max(curr_max, n)
            res.append(curr_max)
        
        return res[::-1]