class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        for i in board:
            mySet = set()
            for j in i:
                if j in mySet:
                    return False
                elif j != ".":
                    mySet.add(j)
        for i in range(len(board[0])):
            mySet = set()
            for j in range(len(board)):
                if board[j][i] in mySet:
                    return False
                elif board[j][i] != ".":
                    mySet.add(board[j][i])
        for i in range(0, len(board), 3):
            for j in range(0, len(board[0]), 3):
                mySet = set()
                for k in range(j, j+ 3):
                    for m in range(i, i+3):
                        if board[m][k] in mySet:
                            return False
                        elif board[m][k] != ".":
                            mySet.add(board[m][k])
        return True