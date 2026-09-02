class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        // nums1 contains both odd and even numbers: Since even minus odd results in an odd number
        // If nums1[i] is odd, then nums2[i] = nums1[i] (the first operation).
        // If nums1[i] is even, then nums2[i] = nums1[i] − nums1[j]
        // In this way, all elements in nums2 will be odd, satisfying the requirements of the problem.
        return true;
    }
};