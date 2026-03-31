class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        d = {}
        l = []
        for i in nums:
            d[i] = d.get(i, 0) + 1
        for _ in range(k):
            l.append(max(d, key=d.get))
            del d[max(d, key=d.get)]
        return l