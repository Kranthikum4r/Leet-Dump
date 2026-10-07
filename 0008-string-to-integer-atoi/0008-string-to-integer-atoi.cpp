class Solution {
public:
    int myAtoi(string s) {
        int n = s.length();

        int i = 0;
        while(i < n && s[i] == ' ') {
            i++;
        }
        
        long long ans = 0;
        bool neg = false;

        for(int j = i; j < n; j++) {
            char c = s[j];

            if(c == '-' || c == '+') {
                if(j == i) {
                    if(c == '-') neg = true;
                }
                else {
                    if(neg) return -ans;
                    return ans;
                }
            }
            else if(c >= '0' && c <= '9') {
                ans = (ans * 10) + (c - '0');
                if(neg) {
                    if(-ans < INT_MIN) {
                        return INT_MIN;
                    }
                }
                else {
                    if(ans > INT_MAX) {
                        return INT_MAX;
                    }
                }
            }
            else {
                return neg ? -ans : ans;
            }
        }
        return neg ? -ans : ans;
    }   
};