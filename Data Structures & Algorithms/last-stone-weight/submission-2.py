class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        h = []
        for i in stones:
            heapq.heappush(h, i * -1)
        while len(h) > 1:
            x = heapq.heappop(h)
            y = heapq.heappop(h)
            res = x - y
            if res != 0:
                heapq.heappush(h, res)
        if h:
            return heapq.heappop(h) * -1
        else:
            return 0