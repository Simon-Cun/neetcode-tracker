#include <vector>
#include <climits>
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) swap(nums1, nums2);
        int n = nums1.size(), m = nums2.size(), total = n + m, half = total / 2;
        int l = -1, r = n - 1;
        while (true) {
            int m1 = l + (r - l) / 2;
            int m2 = half - m1 - 2;

            int arr1Left = (m1 >= 0) ? nums1.at(m1) : INT_MIN;
            int arr1Right = (m1 + 1 < n) ? nums1.at(m1 + 1) : INT_MAX;
            int arr2Left = (m2 >= 0) ? nums2.at(m2) : INT_MIN;
            int arr2Right = (m2 + 1 < m) ? nums2.at(m2 + 1) : INT_MAX;

            if (arr1Left <= arr2Right && arr2Left <= arr1Right) {
                if (total % 2) {
                    return min(arr1Right, arr2Right);
                }
                return (max(arr1Left, arr2Left) + min(arr1Right, arr2Right)) / 2.0;
            } else if (arr1Left < arr2Right) {
                l = m1 + 1;
            } else {
                r = m1 - 1;
            }
        }
    }
};
