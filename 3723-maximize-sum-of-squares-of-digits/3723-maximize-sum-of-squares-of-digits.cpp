class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(sum > 9 * num) return ""; // not possible

        int n = sum / 9; // number of 9's we can use (using 9's maximizes sum)
        int r = sum % 9; // remainder digit

        string ans;
        ans.reserve(num);

        // append n 9's
        ans.append(n, '9'); num -= n;

        // append the remainder digit
        if(r) {
            ans += char('0' + r);
            num--;
        }

        // if number of digits remain, add zeroes
        ans.append(num, '0');

        return ans;
    }
};