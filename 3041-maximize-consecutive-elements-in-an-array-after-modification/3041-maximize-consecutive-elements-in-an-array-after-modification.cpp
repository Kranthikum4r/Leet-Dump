class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        unordered_map<int, int> dp;
        int ans = 0;

        for(int num : nums) {
            dp[num + 2] = max(dp[num + 2], dp[num + 1] + 1);
            dp[num + 1] = max(dp[num + 1], dp[num] + 1);

            ans = max({ans, dp[num + 1], dp[num + 2]});
        }

        return ans;
    }
};