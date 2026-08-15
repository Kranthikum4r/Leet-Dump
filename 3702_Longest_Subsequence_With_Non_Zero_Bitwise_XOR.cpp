class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();

        int xr = 0;
        
        for(int x : nums) {
            xr ^= x;
            if(x != 0) {
                hasNonZero = true;
            }
        }
        if(xr != 0) return n;
        
        for(int x : nums) {
            if(x != 0) {
                return n-1; // remove one non-zero element
            }
        }

        return 0; // if no non-zero (all zeroes) 
    }
};