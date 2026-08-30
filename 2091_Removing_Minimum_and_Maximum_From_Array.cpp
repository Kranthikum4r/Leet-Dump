class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) return 1;

        int mx = max_element(nums.begin(), nums.end()) - nums.begin();
        int mn = min_element(nums.begin(), nums.end()) - nums.begin();

        int ans = INT_MAX;
        ans = min(ans, n - abs(mx - mn) + 1);
        ans = min(ans, max(mx, mn) + 1);
        ans = min(ans, n - min(mx, mn));

        return ans;
    }
};