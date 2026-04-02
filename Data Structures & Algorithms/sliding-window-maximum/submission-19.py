import heapq
class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        heap = []
        res = []

        for i, n in enumerate(nums[0:k]):
            heapq.heappush(heap, (n * -1, i))
        l = 0
        for r, n in enumerate(nums[k:]):
            while not (l <= heap[0][1] <= r + k - 1):
                heapq.heappop(heap)
            else:
                res.append(heap[0][0] * -1)
            heapq.heappush(heap, (n * -1, r + k))
            l += 1
        while heap and not (len(nums) - k - 1 < heap[0][1] <= len(nums) - 1):
            heapq.heappop(heap)
        else:
            res.append(heap[0][0] * -1)
        return res