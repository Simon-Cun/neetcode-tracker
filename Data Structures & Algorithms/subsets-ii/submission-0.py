class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        n = len(nums)
        res = []
        s = set()

        for i in range(1 << n):
            subset = [nums[j] for j in range(n) if (i & (1 << j))]
            subset.sort()
            if tuple(subset) not in s:
                res.append(subset)
            s.add(tuple(subset))
        
        return res