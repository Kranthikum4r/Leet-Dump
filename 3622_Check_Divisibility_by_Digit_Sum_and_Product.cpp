class Solution {
public:
    bool checkDivisibility(int n) {
        int num = n;
        int sum = 0;
        long long product = 1;
        while(num > 0) {
            int d = num % 10;
            sum += d;
            product *= d;
            num /= 10;
        }
        return n % (sum + product) == 0;
    }
};