class Solution:
    def trap(self, height: List[int]) -> int:
        rows = max(height)
        cols = len(height)
        matrix = [[0 for _ in range(cols)] for _ in range(rows)]

        # white is 0
        # blue is 1
        # black is 2

        for i, h in enumerate(height):
            if h == 0:
                continue
            for sub_h in range(h):
                matrix[sub_h][i] = 2
        
        i = 0
        while i < rows and matrix[i].count(2) < 2:
            i += 1

        # i is the tallest row containing at least 2 black bar boxes

        for row in range(i, rows):
            start = matrix[row].index(2)
            matrix_copy = list(reversed(matrix[row]))
            end = cols - 1 - matrix_copy.index(2)
            for num in range(start + 1, end):
                if matrix[row][num] != 2:
                    matrix[row][num] = 1

        return sum(row.count(1) for row in matrix)