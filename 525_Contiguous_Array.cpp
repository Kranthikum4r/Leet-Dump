class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int o = 0, z = 0;

        unordered_map<int, int> ones;
        unordered_map<int, int> zeroes;

        int n = nums.size();
        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] == 1) {
                o++;
                ones[o] = i;
            }
            else {
                z++;
                zeroes[z] = i;
            }
            if(o == z) ans = max(ans, i+1);
            int mn = min(o, z);
            if(ones[mn] == zeroes[mn]) ans = max(ans, i - ones[mn]);
        }

        return ans;
    }
};