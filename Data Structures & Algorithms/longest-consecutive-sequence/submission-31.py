class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        s = set(nums)
        longest = 0
        for i in nums:
            length = 0
            while i - length in s:
                length += 1
            if longest < length:
                longest = length
        return longest