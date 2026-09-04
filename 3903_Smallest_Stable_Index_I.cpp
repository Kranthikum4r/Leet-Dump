class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == 1) return 0;

        vector<int> maxarr(n);
        vector<int> minarr(n);
        int mx = nums.front();
        maxarr[0] = mx;
        for(int i = 1; i < n; i++) {
            if(nums[i] > mx) {
                maxarr[i] = nums[i];
                mx = nums[i];
            }
            else {
                nums[i] = mx;
            }
        }
        int mn = nums.back();
        minarr[n - 1] = mn;
        for(int i = n - 2; i >= 0; i--) {
            if(nums[i] < mn) {
                minarr[i] = nums[i];
                mn = nums[i];
            }
            else {
                nums[i] = mn;
            }
        }
        for(int i = 0; i < n; i++) {
            if(maxarr[i] - minarr[i] <= k)
                return i;
        }
        return -1;
    }
};