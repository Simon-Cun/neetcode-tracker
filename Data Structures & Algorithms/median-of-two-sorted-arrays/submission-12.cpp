class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int total = nums1.size() + nums2.size();
        if (nums1.size() > nums2.size()) swap(nums1, nums2);
        int half = total / 2;
        int l = 0, r = nums1.size();
        while (true) {
            int m1 = l + (r - l) / 2;
            int m2 = half - m1;
            int aLeft = (m1 <= 0) ? INT_MIN : nums1.at(m1 - 1);
            int bLeft = (m2 <= 0) ? INT_MIN : nums2.at(m2 - 1);
            int aRight = (m1 >= nums1.size()) ? INT_MAX : nums1.at(m1);
            int bRight = (m2 >= nums2.size()) ? INT_MAX : nums2.at(m2);
            if (aLeft <= bRight && bLeft <= aRight) {
                if (total % 2 == 0) {
                    return (max(aLeft, bLeft) + min(aRight, bRight)) / 2.0;
                } else {
                    return min(aRight, bRight);
                }
            } else if (aLeft < bRight) {
                l = m1 + 1;
            } else {
                r = m1 - 1;
            }
        }
    }
};
