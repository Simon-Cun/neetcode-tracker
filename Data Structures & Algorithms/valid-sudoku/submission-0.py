class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        for i in board:
            my_set = set()
            for j in i:
                if j == ".":
                    continue
                elif j in my_set:
                    return False
                else:
                    my_set.add(j)
        for m in range(len(board[0])):
            my_set = set()
            for n in range(len(board)):
                if board[n][m] == ".":
                    continue
                elif board[n][m] in my_set:
                    return False
                else:
                    my_set.add(board[n][m])
        for box_row in range(0, 9, 3):
            for box_col in range(0, 9, 3):
                my_set = set()
                for i in range(3):
                    for j in range(3):
                        val = board[box_row + i][box_col + j]
                        if val == ".":
                            continue
                        elif val in my_set:
                            return False
                        else:
                            my_set.add(val)


        return True