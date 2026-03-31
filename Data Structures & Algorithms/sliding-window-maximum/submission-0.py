class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        result = []
        for i in range(k - 1, len(nums)):
            print(nums[i - k + 1:i + 1])
            result.append(max(nums[i - k + 1:i + 1]))
        return result