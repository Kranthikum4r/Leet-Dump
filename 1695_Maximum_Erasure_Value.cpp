class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int, int> freq;

        int left = 0;
        int sum = 0;
        int mx = 0;
        for(int r = 0; r < nums.size(); r++) {
            freq[nums[r]]++;
            sum += nums[r];
            while(freq[nums[r]] > 1) {
                int x = nums[left];
                freq[nums[left]]--;
                sum -= x;
                left++;
            }
            mx = max(sum, mx);
        }
        return mx;
    }
};