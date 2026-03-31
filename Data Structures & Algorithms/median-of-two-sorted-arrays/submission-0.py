class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        small = min(nums1, nums2, key=len)
        large = max(nums2, nums1, key=len)
        total = len(nums1) + len(nums2)
        half = total // 2

        l, r = 0, len(small) - 1
        while True:
            a = (l + r) // 2
            b = half - a - 2

            small_left = small[a] if a >= 0 else float("-inf")
            small_right = small[a + 1] if a + 1 < len(small) else float("inf")
            large_left = large[b] if b >= 0 else float("-inf")
            large_right = large[b + 1] if b + 1 < len(large)  else float("inf")

            if small_left <= large_right and large_left <= small_right:
                if total % 2:
                    return min(small_right, large_right)
                else:
                    return (max(small_left, large_left) + min(small_right, large_right)) / 2
            elif small_left > large_right:
                r = a - 1
            else:
                l = a + 1