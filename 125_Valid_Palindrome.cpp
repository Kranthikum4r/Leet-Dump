class Solution {
public:
    char toLowerChar(char ch) {
        if(ch >= 'A' && ch <= 'Z') {
            return char(ch + 32);
        }
 
        return ch;
    }
    bool isPalindrome(string s) {
        int left = 0, right = s.length() - 1;

        while(left < right) {
            while(left < right && !isalnum(s[left])) {
                left++;
            }
            
            while(left < right && !isalnum(s[left])) {
                right--;
            }

            if(toLowerChar(s[left]) != toLowerChar(s[right])) return false;

            left++;
            right--;
        }
        return true;
    }
};