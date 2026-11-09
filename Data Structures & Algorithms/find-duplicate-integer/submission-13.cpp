class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0;
        int fast = 0;
        while (fast < nums.size()) {
            slow = nums.at(slow);
            fast = nums.at(nums.at(fast));
            if (slow == fast) {
                break;
            }
        }
        slow = 0;
        while (fast != slow) {
            slow = nums.at(slow);
            fast = nums.at(fast);
        }
        return slow;

    }
};
