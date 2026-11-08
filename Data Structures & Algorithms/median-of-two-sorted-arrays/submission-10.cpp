class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int totalSize = nums1.size() + nums2.size();
        int half = totalSize / 2;
        if (nums1.size() > nums2.size()) {
            swap(nums1, nums2);
        }
        int l = 0, r = nums1.size();
        while (true) {
            int i = l + (r - l) / 2;
            int j = half - i;
            int aLeft;
            if (i <= 0) aLeft = INT_MIN;
            else aLeft = nums1.at(i - 1);
            int aRight;
            if (i >= nums1.size()) aRight = INT_MAX;
            else aRight = nums1.at(i);
            int bLeft;
            if (j <= 0) bLeft = INT_MIN;
            else bLeft = nums2.at(j - 1);
            int bRight;
            if (j >= nums2.size()) bRight = INT_MAX;
            else bRight = nums2.at(j);
            if (aLeft <= bRight && bLeft <= aRight) {
                if (totalSize % 2) {
                    return min(bRight, aRight);
                } else {
                    return (max(aLeft, bLeft) + min(aRight, bRight)) / 2.0;
                }
            } else if (aLeft > bRight) {
                r = i - 1;
            } else {
                l = i + 1;
            }
        }
    }
};
