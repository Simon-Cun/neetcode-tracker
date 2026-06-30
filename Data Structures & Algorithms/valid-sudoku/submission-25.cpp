class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<int> row(9, 0), col(9, 0), box(9, 0);
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board.at(i).at(j) == '.') continue;
                int bitmask = 1 << board.at(i).at(j) - '0';
                int boxIdx = ((i / 3) * 3 + (j / 3));

                if ((row.at(i) & bitmask) or (col.at(j) & bitmask) or (box.at(boxIdx) & bitmask)) return false;
                row.at(i) |= bitmask;
                col.at(j) |= bitmask;
                box.at(boxIdx) |= bitmask;
            }
        }
        return true;
    }
};
