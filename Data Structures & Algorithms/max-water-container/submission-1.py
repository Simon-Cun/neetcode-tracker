class Solution:
    def maxArea(self, heights: List[int]) -> int:
        x = list()
        for i in range(len(heights)):
            for j in range(i, len(heights)):
                x.append(min(heights[i], heights[j]) * (j - i))
        return max(x)