class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0, r = numbers.size() - 1;
        while (l < r) {
            int currSum = numbers.at(l) + numbers.at(r);
            if (currSum == target) {
                return {l + 1, r + 1};
            } else if(currSum < target) {
                ++l;
            } else {
                --r;
            }
        }
        return {0, 0};

    }
};
