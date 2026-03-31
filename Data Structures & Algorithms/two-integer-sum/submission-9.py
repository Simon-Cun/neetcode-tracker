class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        dictionary = {}
        for i, n in enumerate(nums):
            diff = target - n
            if diff in dictionary:
                return [dictionary[diff], i]
            dictionary[n] = i