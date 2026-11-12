class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        if(nums.size() == 1) return 1;

        int prev = -1;
        int inc = 1, dec = 1, maxlen = 1;

        for(int x : nums) {
            if(prev == -1) {
                prev = x;
            }
            else if(prev < x) {
                inc++;
                maxlen = max(maxlen, dec);
                dec = 1;
            }
            else if(prev > x) {
                dec++;
                inc = 1;
            }
            else {
                inc = 1;
                dec = 1;
            }
            prev = x;
            maxlen = max(maxlen, max(inc, dec));
        }

        return maxlen;
    }
};