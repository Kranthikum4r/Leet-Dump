class Solution {
public:
    int countCommas(int n) {
        if(n < 999) return 0;

        // since, range of n <= 10^5 (n <= 100,000)
        return n - 999;
    }
};