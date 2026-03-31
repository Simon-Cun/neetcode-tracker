class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        for i in range(len(board)):
            my_set = set()
            for j in range(len(board[0])):
                if board[i][j] == ".":
                    continue
                if board[i][j] in my_set:
                    return False
                else:
                    my_set.add(board[i][j])
        for i in range(len(board)):
            my_set = set()
            for j in range(len(board[0])):
                if board[j][i] == ".":
                    continue
                if board[j][i] in my_set:
                    return False
                else:
                    my_set.add(board[j][i])
        for i in range(0, len(board), 3):
            for j in range(0, len(board[0]), 3):
                my_set = set()
                for k in range(i, i + 3):
                    for l in range(j, j + 3):
                        if board[k][l] == ".":
                            continue
                        if board[k][l] in my_set:
                            return False
                        else:
                            my_set.add(board[k][l])
        return True

