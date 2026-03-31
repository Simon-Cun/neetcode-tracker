class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        prefix = []

        for i in range(len(nums)):
            if i == 0:
                prefix.append(1)
            else:
                product = 1
                for i in nums[0:i]:
                    product *= i
                prefix.append(product)
        
        postfix = []

        for i in range(len(nums)):
            if i == len(nums):
                prefix.append(1)
            else:
                product = 1
                for i in nums[i + 1:len(nums)]:
                    product *= i
                postfix.append(product)

        res = []

        for i, j in zip(prefix, postfix):
            res.append(i * j)

        return res