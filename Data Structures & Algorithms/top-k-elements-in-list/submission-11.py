class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        freq_map = {}

        for i, n in enumerate(nums):
            freq_map[n] = freq_map.get(n, 0) + 1

        bucket = [[] for _ in range(len(nums) + 1)]

        for i, j in freq_map.items():
            bucket[j].append(i)

        res = []

        for i in bucket:
            if i:
                res.extend(i)
        
        res.reverse()

        return res[0:k]
