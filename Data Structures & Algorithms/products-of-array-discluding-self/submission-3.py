class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        prefix = []
        postfix = []
        res = []
        for i, n in enumerate(nums):
            if i == 0:
                prefix.append(1)
            else:
                multi = 1
                for j in nums[0 : i]:
                    multi *= j
                prefix.append(multi)
        for i, n in enumerate(nums):
            if i == len(nums) - 1:
                postfix.append(1)
            else:
                multi = 1
                for j in nums[i + 1 : len(nums)]:
                    multi *= j
                postfix.append(multi)
        for i in range(len(nums)):
            res.append(postfix[i] * prefix[i])
        return res