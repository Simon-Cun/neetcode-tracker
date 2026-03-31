class Solution:
    def replaceElements(self, arr: List[int]) -> List[int]:
        n = len(arr)
        curr_max = -1
        for i in range(n - 1, -1, -1):
            arr[i], curr_max = curr_max, max(curr_max, arr[i])
        return arr