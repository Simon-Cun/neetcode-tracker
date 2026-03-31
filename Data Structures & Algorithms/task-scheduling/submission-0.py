class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        q = deque()
        h = []
        freq = {}
        time = 0
        for i in tasks:
            freq[i] = freq.get(i, 0) + 1
        for i in list(freq.values()):
            heapq.heappush(h, -1 * i)
        while h or q:
            if h:
                value = heapq.heappop(h) + 1
                if value != 0:
                    q.append([value, time + n + 1])
            time += 1
            if q and q[0][1] <= time:
                heapq.heappush(h, q.popleft()[0])
        return time
