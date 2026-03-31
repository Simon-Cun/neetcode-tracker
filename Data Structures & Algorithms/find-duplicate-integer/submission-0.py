class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        my_set = set()
        for i in nums:
            if i in my_set:
                return i
            else:
                my_set.add(i)
        return -1
        