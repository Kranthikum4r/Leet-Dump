class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {

        sort(nums.begin(), nums.end());

        int n = nums.size();
        
        int l = 0, r = n-1;
        int ans = 0;

        while(l < r) {
            long long sum = nums[l] + nums[r];

            if(sum == k) {
                ans++;
                l++;
                r--;
            }
            else if(sum > k) {
                r--;
            }
            else {
                l++;
            }
        }
        return ans;
    }
};