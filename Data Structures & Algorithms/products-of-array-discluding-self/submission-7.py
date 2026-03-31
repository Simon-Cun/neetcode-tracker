class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = len(nums)
        
        prefix_array = [1] * n
        postfix_array = [1] * n

        prefix = 1

        for i in range(n):
            prefix_array[i] *= prefix
            prefix *= nums[i]

        postfix = 1

        for i in range(n -1, -1, -1):
            postfix_array[i] *= postfix
            postfix *= nums[i]

        res = []

        for i, j in zip(prefix_array, postfix_array):
            res.append(i * j)

        return res
