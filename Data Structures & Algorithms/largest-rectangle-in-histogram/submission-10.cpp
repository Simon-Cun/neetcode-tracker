#include <stack>
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> left(heights.size()), right(heights.size());
        stack<int> leftBoundaries;
        for (int i = 0; i < heights.size(); ++i) {
            while (true) {
                if (leftBoundaries.empty()) {
                    left.at(i) = 0;
                    leftBoundaries.push(i);
                    break;
                } else if (heights.at(i) <= heights.at(leftBoundaries.top())) {
                    leftBoundaries.pop();
                } else {
                    left[i] = leftBoundaries.top() + 1;
                    leftBoundaries.push(i);
                    break;
                }
            }
        }
        stack<int> rightBoundaries;
        for (int i = heights.size() - 1; i >= 0; --i) {
            while (true) {
                if (rightBoundaries.empty()) {
                    rightBoundaries.push(i);
                    right.at(i) = heights.size() - 1;
                    break;
                } else if (heights.at(i) <= heights.at(rightBoundaries.top())) {
                    rightBoundaries.pop();
                } else {
                    right.at(i) = rightBoundaries.top() - 1;
                    rightBoundaries.push(i);
                    break;
                }
            }
        }
        int res = 0;
        for (int i = 0; i < heights.size(); i++) {
            res = max(res, heights[i] * (right[i] - left[i] + 1));
        }
        return res;
    }
};