class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        for(int &x : nums) x *= x;

        sort(nums.begin(), nums.end());

        long long sum = 0;
        int mid = n / 2;
         
        for(int i = 0; i < mid; i++) {
            sum -= nums[i];
        }
        for(int i = mid; i < n; i++) {
            sum += nums[i];
        }

        return sum;
    }
};