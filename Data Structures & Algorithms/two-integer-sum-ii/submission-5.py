class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        d = {}
        for i, n in enumerate(numbers):
            diff = target - n
            if diff in d:
                return [d[diff] + 1, i + 1]
            d[n] = i
        return []