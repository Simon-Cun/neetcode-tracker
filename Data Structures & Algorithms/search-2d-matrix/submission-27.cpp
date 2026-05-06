class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l = 0, r = (matrix.size() * matrix.at(0).size()) - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            int row = m / matrix.at(0).size(), col = m % matrix.at(0).size();
            if (matrix.at(row).at(col) == target) {
                return true;
            } else if (matrix.at(row).at(col) < target) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return false;
    }
};
