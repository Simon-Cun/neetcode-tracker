class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        freq_map = {}
        for i in nums:
            freq_map[i] = freq_map.get(i, 0) + 1

        buckets = [[] for _ in range(len(nums) + 1)]
        for i, j in freq_map.items():
            buckets[j].append(i)
        
        res = []
        for i in buckets:
            if i:
                res.extend(i)
        res.reverse()

        return res[0:k]