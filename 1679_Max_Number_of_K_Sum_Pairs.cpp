class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int, int> mp;
        mp[0] = 1;
    
        int ans = 0;
        sort(nums.begin(), nums.end());

        int l = 0, r = n-1;

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