class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        s = set(nums)
        curr = 1
        curr_max = 0
        for i in s:
            curr = 1
            if i + 1 in s:
                continue
            l = i
            while l - 1 in s:
                l -= 1
                curr += 1
            curr_max = max(curr_max, curr)
        
        return curr_max
