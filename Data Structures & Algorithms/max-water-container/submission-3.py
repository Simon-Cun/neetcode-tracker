class Solution:
    def maxArea(self, heights: List[int]) -> int:
        l, r = 0, len(heights) - 1
        max_heights = 0
        while l < r:
            length = r - l
            smaller_heights = min(heights[l], heights[r])
            water = smaller_heights * length
            max_heights = max(water, max_heights)
            if heights[l] < heights[r]:
                l += 1
            else:
                r -= 1
        return max_heights
            