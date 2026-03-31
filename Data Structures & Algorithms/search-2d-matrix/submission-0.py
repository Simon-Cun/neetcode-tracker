class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        first = 0
        last = len(matrix[0]) * len(matrix) - 1

        while first <= last:
            middle = int((last + first) / 2)
            row = int(middle / len(matrix[0]))
            col = middle % len(matrix[0])
            if matrix[row][col] == target:
                return True
            elif matrix[row][col] < target:
                first = middle + 1
            else:
                last = middle - 1
        return False