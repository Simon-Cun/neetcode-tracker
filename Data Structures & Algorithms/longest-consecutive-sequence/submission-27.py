class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        mySet = set(nums)
        longest = 0
        for i in mySet:
            if (i - 1) not in mySet:
                length = 1
                while (i + length) in mySet:
                    length += 1
                longest = max(length, longest)
        return longest