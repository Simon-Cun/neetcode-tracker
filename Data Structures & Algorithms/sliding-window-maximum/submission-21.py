class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        n = len(nums)
        res = []
        q = deque()
        l = r = 0
        while r < n:
            while q and nums[q[-1]] < nums[r]:
                q.pop()
            q.append(r)

            if q[0] < l:
                q.popleft()
            
            if r + 1 >= k:
                res.append(nums[q[0]])
                l += 1
            r += 1
        return res