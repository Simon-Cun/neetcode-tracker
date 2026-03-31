class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        prefix = []
        postfix = []
        res = []
        for i in range(len(nums)):
            if i == 0:
                prefix.append(1)
            else:
                product = 1
                for j in nums[0 : i]:
                    product *= j
                prefix.append(product)
        for i in range(len(nums)):
            if i == len(nums) - 1:
                postfix.append(1)
            else:
                product = 1
                for j in nums[i + 1 : len(nums)]:
                    product *= j
                postfix.append(product)
        for i in range(len(nums)):
            res.append(prefix[i] * postfix[i])
        return res