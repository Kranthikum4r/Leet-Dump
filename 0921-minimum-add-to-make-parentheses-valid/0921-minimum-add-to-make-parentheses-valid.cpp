class Solution {
public:
    int minAddToMakeValid(string s) {
        int open = 0;
        
        int ans = 0;
        for(char c : s) {
            if(c == '(') {
                open++;
            }
            else {
                open > 0 ? open-- : ans++;
            }
        }
    
        return ans + open;
    }
};