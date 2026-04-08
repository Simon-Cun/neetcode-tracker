class Solution {
public:
    bool simulate(vector<int>& pilesOfBananas, int eatingRate, int hours) {
        int count = 0;
        for (auto& n : pilesOfBananas) {
            count += (n + eatingRate - 1) / eatingRate;
            if (count > hours)
            {
                return false;
            }
        }
        return count <= hours;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = *max_element(piles.begin(), piles.end());
        int res = -1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (simulate(piles, m, h)) {
                res = m;
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return res;
    }
};