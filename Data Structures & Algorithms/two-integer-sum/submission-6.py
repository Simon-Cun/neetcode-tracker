class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        returnList = [int] * 2
        for i in range(len(nums)):
            returnList[0] = i
            for j in range(i + 1, len(nums)):
                if nums[i] + nums[j] == target:
                    returnList[1] = j
                    return returnList
        return returnList