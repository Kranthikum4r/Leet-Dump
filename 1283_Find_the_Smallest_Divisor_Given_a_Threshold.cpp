class Solution {
public:
    int result(vector<int>& nums, int k) {
        int res = 0;
        for(int num : nums) {
            res += (num + k - 1) / k;
        }
        return res;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int ans;
        int l = 1;
        int h = *max_element(nums.begin(), nums.end());
        while(l <= h) {
            int mid = l + (h - l) / 2;

            if(result(nums, mid) <= threshold) {
                ans = mid;
                h = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        return ans;
    }
};