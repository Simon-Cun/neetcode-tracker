class Solution {
public:
    bool canEatAll(vector<int> piles, int h, int eatingRate) {
        int curr = 0;
        for (int i = 0; i < piles.size(); ++i) {
            curr += ceil((double)piles.at(i) / eatingRate);
        }
        return curr <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = *max_element(piles.begin(), piles.end());
        int ret = r;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (canEatAll(piles, h, m)) {
                ret = min(ret, m);
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return ret;
    }
};
