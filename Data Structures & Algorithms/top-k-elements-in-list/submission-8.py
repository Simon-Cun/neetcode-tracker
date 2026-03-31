class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        n = len(nums)

        d = {}

        for i in nums:
            d[i] = d.get(i, 0) + 1
        
        buckets = [[] for _ in range(n + 1)]

        for i, v in d.items():
            buckets[v].append(i)

        print(buckets)

        res = []

        for i in reversed(buckets):
            if i:
                res.extend(i)
            if len(res) >= k:
                break

        return res[0:k]