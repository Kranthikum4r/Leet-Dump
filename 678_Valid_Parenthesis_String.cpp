class Solution {
public:
    vector<vector<int>> dp;

    bool solve(string& s, int i, int open) {
        // too much )
        if(open < 0)
            return false;

        if(i == s.length()) {
            return open == 0;
        }

        if(dp[i][open] != -1)
            return dp[i][open];
        
        if(s[i] == '(') {
            return dp[i][open] = solve(s, i + 1, open + 1);
        }

        else if(s[i] == ')') {
            return dp[i][open] = solve(s, i + 1, open - 1);
        }

        else {

            bool a = solve(s, i + 1, open + 1);

            bool b = solve(s, i + 1, open - 1);
            
            bool c = solve(s, i + 1, open);

            return a || b || c;
        }
    }
    bool checkValidString(string s) {
        int n = s.length();

        dp.assign(n, vector<int>(n+1, -1));
        
        return solve(s, 0, 0);
    }
};