class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        d = {}
        res = []
        for i in nums:
            d[i] = d.get(i, 0) + 1
        for i in range(k):
            res.append(max(d, key=d.get))
            del d[max(d, key=d.get)]
        return res