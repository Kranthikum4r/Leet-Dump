class Solution {
public:
    void revstr(vector<char> &s, int left, int right) {
        if(left >= right) {
            return;
        }

        swap(s[left], s[right]);

        revstr(s, left + 1, right - 1);
    }
    void reverseString(vector<char>& s) {
        revstr(s, 0, s.size() - 1);
    }
};