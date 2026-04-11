#include <vector>
#include <deque>
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> res;
        int l = 0;
        for (int r = 0; r < nums.size(); ++r) {
            while (!dq.empty() and nums.at(r) >= nums.at(dq.back())) {
                dq.pop_back();
            }
            dq.push_back(r);
            for (int val : dq) {
                std::cout << val << " ";
            }
            cout << endl;

            if (r - l + 1 >= k) {
                res.push_back(nums.at(dq.front()));
                ++l;
            }

            if (l > dq.front()) {
                dq.pop_front();
            }
        }
        return res;
    }
};
