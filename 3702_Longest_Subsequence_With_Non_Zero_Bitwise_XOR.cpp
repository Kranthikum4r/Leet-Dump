class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();

        int len = 0;
        int left = 0;
        int xr = 0;
        for(int right = 0; right < n; right++) {
            xr ^= nums[right];
            if(xr == 0) {
                len = 0;
                left++;
            }
            else {
                len = max(len, right - left + 1);
            }
        }
        return len;
    }
};