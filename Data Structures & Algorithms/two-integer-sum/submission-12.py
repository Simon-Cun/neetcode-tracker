class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        dictionary = {}
        for i in range(len(nums)):
            diff = target - nums[i]
            if diff in dictionary:
                return [dictionary[diff], i]
            dictionary[nums[i]] = i
        return []