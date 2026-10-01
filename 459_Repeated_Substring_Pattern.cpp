class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        for(int i = 0; i < s.length(); i++) {
            if(s.length() % (i + 1) == 0) {
                string str = s.substr(0, i + 1);

                int j = i + 1;
                while(j < s.length()) {
                    if(s.substr(j, str.length()) != str) {
                        return false;
                    } 
                    j += str.length();
                }
                return true;
            }
        }
        return false;
    }
};