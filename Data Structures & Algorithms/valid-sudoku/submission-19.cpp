class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; ++i) {
            int bitMask = 0;
            for (int j = 0; j < 9; ++j) {
                if (board.at(i).at(j) == '.') {
                    continue;
                }
                int value = 1 << (board.at(i).at(j) - '0');
                if ((bitMask & value) != 0) {
                    return false;
                } else {
                    bitMask |= value;
                }
            }
        }
        for (int i = 0; i < 9; ++i) {
            int bitMask = 0;
            for (int j = 0; j < 9; ++j) {
                if (board.at(j).at(i) == '.') {
                    continue;
                }
                int value = 1 << (board.at(j).at(i) - '0');
                if ((bitMask & value) != 0) {
                    return false;
                } else {
                    bitMask |= value;
                }
            }
        }
        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 9; j += 3) {
                int bitMask = 0;
                for (int k = i; k < i + 3; ++k) {
                    for (int l = j; l < j + 3; ++l) {
                        if (board.at(k).at(l) == '.') {
                            continue;
                        }
                        int value = 1 << (board.at(k).at(l) - '0');
                        if ((bitMask & value) != 0) {
                            return false;
                        } else {
                            bitMask |= value;
                        }
                    }
                }
            }
        }
        return true;
    }
};
