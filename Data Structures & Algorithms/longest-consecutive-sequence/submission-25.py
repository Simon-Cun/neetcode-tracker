class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        
        if not nums:
            return 0
        if len(nums) == 1:
            return 1
        
        s = list(set(nums))
        s = sorted(s)
        print(s)

        m = 1
        count = 1
        for i, n in enumerate(s[:-1]):
            if n == s[i + 1] - 1:
                count += 1
            if m <= count:
                m = count
            if n != s[i + 1] - 1:
                count = 1
        return m