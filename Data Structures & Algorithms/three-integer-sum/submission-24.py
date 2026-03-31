class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        res = []
        for i in range(len(nums)):
            dictionary = {}
            for j in range(len(nums)):
                s = -1 * (nums[i] + nums[j])
                if j == i:
                    continue
                if s in dictionary:
                    if sorted([nums[dictionary[s]], nums[i], nums[j]]) not in res:
                        res.append(sorted([nums[dictionary[s]], nums[i], nums[j]]))
                dictionary[nums[j]] = j
        return res
                     