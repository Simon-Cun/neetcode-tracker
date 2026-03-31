class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        upper = max(piles)
        lower = 0
        minimum = 0
        while lower <= upper:
            pivot = int((upper + lower) / 2)
            if pivot == 0:
                break
            time = 0
            for i in piles:
                time += -(-i // pivot)
            if time <= h:
                minimum = pivot
                upper = pivot - 1
            else:
                lower = pivot + 1
        return minimum
        
            