class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        matrix = [[0] * len(heights) for _ in range(max(heights))]

        for i in range(len(heights)):
            for j in range(heights[i]):
                matrix[max(heights) - j - 1][i] += 1

        for row in matrix:
            print(row)

        height = 0
        rect = 0
        for i in reversed(range(len(matrix))):
            height += 1
            max_len = 0
            length = 0
            for i in matrix[i]:
                if i != 0:
                    length += 1
                else:
                    length = 0
                max_len = max(max_len, length)

            if rect < height * max_len:
                rect = height * max_len
        
        return rect