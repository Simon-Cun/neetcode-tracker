class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ret;
        int l = 0;
        for (int i = 0; i < nums.size(); ++i) {
            while (!dq.empty() && nums.at(dq.back()) < nums.at(i)) {
                dq.pop_back();
            }
            dq.push_back(i);
            if (dq.front() < l) dq.pop_front();
            if (i - l + 1 >= k) {
                ret.push_back(nums.at(dq.front()));
                ++l;
            }
        }
        return ret;
    }
};
