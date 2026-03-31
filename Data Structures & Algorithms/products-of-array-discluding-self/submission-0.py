class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        prefix = [nums[0]]
        postfix = [0] * len(nums)
        array = []
        postfix[len(nums) - 1] = nums[len(nums) - 1]
        for i in range(1, len(nums)):
            prefix.append(nums[i] * prefix[i - 1])
        for j in range(2, len(nums) + 1):
            postfix[len(nums) - j] = nums[len(nums) - j] * postfix[len(nums) - j + 1]
        for k in range(len(nums)):
            if k == 0:
                array.append(postfix[k + 1]) 
            elif k == len(nums) - 1:
                array.append(prefix[k - 1]) 
            else:
                array.append(prefix[k - 1] * postfix[k + 1])
            
        return array