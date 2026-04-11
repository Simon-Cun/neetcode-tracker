class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0, r = numbers.size() - 1;
        while (l < r) {
            int s = numbers.at(l) + numbers.at(r);
            if (s == target) {
                return {l + 1, r + 1};
            } else if (s > target) {
                --r;
            } else {
                ++l;
            }
        }
        return {0, 0};
    }
};
