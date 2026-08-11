class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long ans = 0;
        long long sum = 0;

        unordered_map<int, int> freq;
        
        int left = 0;
        
        for(int right = 0; right < nums.size(); right++) {
            freq[nums[right]]++;
            sum += freq[nums[right]];
            
            while(right - left + 1 > k) {
                freq[nums[left]]--;
                sum -= nums[left];

                if(freq[nums[left]] == 0)
                    freq.erase(nums[left]);

                left++;
            }
            // Window has exactly k elements
            if(right - left + 1 == k && freq.size() == k) {
                ans = max(ans, sum);
            }
        }
        return ans;
    }
};