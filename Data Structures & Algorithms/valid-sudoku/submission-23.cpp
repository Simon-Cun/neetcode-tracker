class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<int> row(9), col(9), box(9);
        for (int r = 0; r < 9; ++r) {
            for (int c = 0; c < 9; ++c) {
                if (board.at(r).at(c) == '.') continue;
                int val = board.at(r).at(c) - '0';

                int bitmask = 1 << val;
                
                if (row.at(r) & bitmask || col.at(c) & bitmask || box.at((r / 3) * 3 + (c / 3)) & bitmask) return false;
                row.at(r) |= bitmask;
                col.at(c) |= bitmask;
                box.at((r / 3) * 3 + (c / 3)) |= bitmask;
            }
        }
        return true;
    }
};
