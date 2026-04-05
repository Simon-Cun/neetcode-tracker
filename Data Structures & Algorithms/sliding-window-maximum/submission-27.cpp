#include <deque>
#include <vector>
#include <algorithm>
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> monotonicQueue;
        vector<int> res;
        int l = 0;
        for (int r = 0; r < nums.size(); ++r) {
            while (!monotonicQueue.empty() and nums.at(r) > nums.at(monotonicQueue.back())) {
                monotonicQueue.pop_back();
            }
            monotonicQueue.push_back(r);
            
            if (!monotonicQueue.empty() && monotonicQueue.front() < l) {
                monotonicQueue.pop_front();
            }

            if (r - l + 1 >= k) {
                res.push_back(nums.at(monotonicQueue.front()));
                ++l;
            }
            
            
        }
        return res;
    }
};
