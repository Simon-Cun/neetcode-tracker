class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ret;
        int l = 0;
        for (int r = 0; r < nums.size(); ++r) {
            
            while (!dq.empty() and nums.at(dq.back()) <= nums.at(r)) dq.pop_back();
            dq.push_back(r);
            for (auto & i : dq) cout << nums.at(i) << ' ';
            cout << endl;

            if (r - l + 1 >= k) {
                ++l;
                ret.push_back(nums.at(dq.front()));
            }

            if (dq.front() < l) dq.pop_front();
        }
        return ret;
    }
};
