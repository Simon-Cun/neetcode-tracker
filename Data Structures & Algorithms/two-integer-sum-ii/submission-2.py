class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        mySet = set()
        for i in numbers:
            mySet.add(i)
        for i in numbers:
            if target - i in mySet:
                return [numbers.index(min(target - i, i)) + 1, numbers.index(max(target - i, i)) + 1]
        return []

        