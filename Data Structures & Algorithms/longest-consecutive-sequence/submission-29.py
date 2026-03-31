class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        my_set = set()
        for i in nums:
            my_set.add(i)
        maxx = 0
        count = 1
        for i in sorted(list(my_set)):
            count += 1
            if i + 1 not in my_set:
                count = 1
            if maxx < count:
                maxx = count
        return maxx