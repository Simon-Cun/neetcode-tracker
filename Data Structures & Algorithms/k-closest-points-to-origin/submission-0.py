class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        h = []
        res = []
        for i in range(len(points)):
            heapq.heappush(h, (((points[i][0]**2 + points[i][1]**2)**(0.5), i)))
        for _ in range(k):
            res.append(points[heapq.heappop(h)[1]])
        return res
