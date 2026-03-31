class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        for i in range(len(board)):
            s = set()
            for j in range(len(board[0])):
                if board[j][i] in s:
                    return False
                elif board[j][i] != '.':
                    s.add(board[j][i])
        for i in range(len(board[0])):
            s = set()
            for j in range(len(board)):
                if board[i][j] in s:
                    return False
                elif board[i][j] != '.':
                    s.add(board[i][j])
        for i in range(0, len(board), 3):
            for j in range(0, len(board[0]), 3):
                s = set()
                for k in range(i, i + 3):
                    for l in range(j, j + 3):
                        if board[k][l] in s:
                            return False
                        elif board[k][l] != '.':
                            s.add(board[k][l])
        return True

        return True