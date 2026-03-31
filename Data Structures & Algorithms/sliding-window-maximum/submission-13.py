import heapq
class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        n = len(nums)
        
        heap = []
        for i in range(0, k - 1):
            heapq.heappush(heap, (-nums[i], i))

        res = []
        for i in range(k - 1, n):
            heapq.heappush(heap, (-nums[i], i))
            if i - k < heap[0][1] <= i:
                res.append(heap[0][0] * -1)
            else:
                while not(i - k < heap[0][1] <= i):
                    heapq.heappop(heap)
                res.append(heap[0][0] * -1)
        return res

        