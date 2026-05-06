class Solution {
public:
    bool withinTime(vector<int>& piles, int h, double k) {
        int currHours = 0;
        for (auto& i : piles) {
            currHours += ceil(i / k);
            if (currHours > h) return false;
        }
        cout << endl;
        cout << "pass" << endl;
        return currHours <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = *max_element(piles.begin(), piles.end());
        int ret = INT_MAX;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (withinTime(piles, h, m)) {
                ret = min(ret, m);
                r = m - 1;
                cout << 'r' << endl;
            } else {
                l = m + 1;
                cout << 'l' << endl;
            }
        }
        return ret;
    }
};
