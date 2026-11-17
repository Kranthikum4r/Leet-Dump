class Solution {
public:
    int trailingZeroes(int n) {
        if(n <= 4) return 0;
        int ans = 0;
        int x = n / 5;

        while(x > 0) {
            ans += x;
            x /= 5;
        }

        return ans;
    }
};