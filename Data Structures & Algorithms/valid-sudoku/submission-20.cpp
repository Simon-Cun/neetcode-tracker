class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; ++i) {
            int bitmask = 0;
            for (int j = 0; j < 9; ++j) {
                int value = board.at(i).at(j) - '0';
                if (value == -2) continue;
                if (((1 << value) & bitmask) == 0) bitmask |= 1 << value;
                else return false;
            }
        }
        for (int i = 0; i < 9; ++i) {
            int bitmask = 0;
            for (int j = 0; j < 9; ++j) {
                int value = board.at(j).at(i) - '0';
                if (value == -2) continue;
                if (((1 << value) & bitmask) == 0) bitmask |= 1 << value;
                else return false;
            }
        }
        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 9; j += 3) {
                int bitmask = 0;
                for (int k = i; k < i + 3; ++k) {
                    for (int l = j; l < j + 3; ++l) {
                        int value = board.at(k).at(l) - '0';
                        if (value == -2) continue;
                        if (((1 << value) & bitmask) == 0) bitmask |= 1 << value;
                        else return false;
                    }
                }
            }
        }
        return true;
    }
};
