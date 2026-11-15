class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1e9 + 7;

        long long even = 1, odd = 0;
        long long ans = 0;

        int sum = 0;
        // A subarray sum is odd when:
        // - Prefix sum at the ending index is odd and prefix sum before the starting index is even.
        // - Prefix sum at the ending index is even and prefix sum before the starting index is odd.

        for(int x : arr) {
            sum += x;

            if(sum % 2 == 0) {
                ans += odd; // the sums with odd prefix sum(starting) and even prefix sum(ending)
                even++;
            }
            else {
                ans += even; // the sums with even prefix sum(starting) and odd prefix sum(ending)
                odd++;
            }

            ans %= MOD;
        }

        return ans;
    }
};