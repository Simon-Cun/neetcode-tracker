class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<int> rows(9, 0), cols(9, 0), boxes(9, 0);
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                int bitmask = 1;
                if (board.at(i).at(j) == '.') continue;
                else bitmask <<= (board.at(i).at(j) - '0');
                int box = i / 3 + (j / 3 * 3);
                if ((rows.at(i) & bitmask) == 0 && (cols.at(j) & bitmask) == 0
                && (boxes.at(box) & bitmask) == 0) {
                    rows.at(i) |= bitmask;
                    cols.at(j) |= bitmask;
                    boxes.at(box) |= bitmask;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};
