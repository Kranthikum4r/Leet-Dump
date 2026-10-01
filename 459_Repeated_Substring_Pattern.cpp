class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.length();
        
        for(int i = 0; i < s.length(); i++) {
            string str = s.substr(0, i + 1);

            if(n % str.length() != 0) {
                continue;
            }

            int j = i + 1;
            while(j < n) {
                if(s.substr(j, str.length()) != str) {
                    break;
                } 
                j += str.length();
            }
            
            if(j == n) return true;
        }
        return false;
    }
};