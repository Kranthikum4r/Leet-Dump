class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(sum > 9 * num) return "";

        string ans;

        while(num--) {
            int digit = min(9, sum); // keeping 9's makes square sum maximum
            ans += char('0' + digit);
            sum -= digit;
        }

        return sum == 0 ? ans : "";
    }
};