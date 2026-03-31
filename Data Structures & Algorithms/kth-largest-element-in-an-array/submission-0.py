import heapq
class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        h = []
        for i in nums:
            heapq.heappush(h, (-1 * i))
        for _ in range(k - 1):
            heapq.heappop(h)
        return heapq.heappop(h) * -1