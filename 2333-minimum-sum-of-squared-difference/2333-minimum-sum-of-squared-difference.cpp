class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        vector<int> diff(n);
        int k = k1 + k2;

        int M = 0;
        for(int i = 0; i < n; i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            M = max(M, diff[i]);
        }

        vector<int> bucket(M + 1, 0);
        for(int x : diff) bucket[x]++;

        for(int i = M; i > 0 && k > 0; i--) {
            int take = min(bucket[i], k);
            bucket[i] -= take;
            bucket[i - 1] += take;
            k -= take;
        }

        long long ans = 0;
        for(int i = 1; i <= M; i++) {
            ans += (1LL * bucket[i] * i * i);
        }

        return ans;
    }
};