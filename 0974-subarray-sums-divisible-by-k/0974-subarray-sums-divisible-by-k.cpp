class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<long long> freq(k, 0);
        freq[0] = 1;

        long long sum = 0;
        long long ans = 0;

        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            int rem = ((sum % k) + k) % k;
            ans += freq[rem];
            freq[rem]++;
        }
        return ans;
    }
};