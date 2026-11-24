class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for(int i = 0; i < n; i++) {
            long long lcmVal = nums[i];
            long long gcdVal = nums[i];
            long long product = nums[i];
            
            for(int j = i + 1; j < n; j++) {
                product *= nums[j];

                lcmVal = lcm(lcmVal, nums[j]);
                gcdVal = gcd(gcdVal, nums[j]);

                if(product > lcmVal * gcdVal) {
                    break;
                }
                
                if(product == lcmVal * gcdVal) {
                    ans = max(ans, j - i + 1);
                }
            }
        }

        return ans;
    }
};