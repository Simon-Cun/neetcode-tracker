class Solution {
public:
    bool canEat(vector<int>& piles, int h, int r) {
        for (auto& i : piles) {
            if (h < 0) return false;
            h -= (i + r - 1) / r;
        }
        return h >= 0;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = *max_element(piles.begin(), piles.end());
        while (l < r) {
            int m = l + (r - l) / 2;
            if (canEat(piles, h, m)) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        return r;
    }
};
