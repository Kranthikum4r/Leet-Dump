class Solution {
public:

    bool isPalindrome(string s) {
        int left = 0, right = s.length() - 1;

        while(left < right) {
            while(left < right && !isalnum(s[left])) {
                left++;
            }
            
            while(left < right && !isalnum(s[left])) {
                right--;
            }

            if(char(s[left] - 32) != char(s[right] - 32)) return false;

            left++;
            right--;
        }
        return true;
    }
};