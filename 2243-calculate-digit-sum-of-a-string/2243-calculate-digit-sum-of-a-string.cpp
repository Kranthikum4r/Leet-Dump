class Solution {
public:
    string sumStr(string s) {
        int sum = 0;

        for(char c : s) {
            sum += (c - '0');
        }
        return to_string(sum);
    }
    string digitSum(string s, int k) {
        string ans, prev;

        while(s.length() > k) {
            string ans = "";

            for(int i = 0; i < s.length(); i += k) {
                string temp = s.substr(i, k);

                ans += sumStr(temp);
            }
            s = ans; 
        }

        return s;
    }
};