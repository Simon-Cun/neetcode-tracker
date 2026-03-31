class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        dictionary = {}
        for i, n in enumerate(numbers):
            diff = target - n
            if diff in dictionary:
                return [dictionary[diff] + 1, i + 1]
            else:
                dictionary[n] = i
        return []
