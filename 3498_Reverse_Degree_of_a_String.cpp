class Solution {
public:
    int reverseDegree(string s) {
        unordered_map<char, int> mp;
        char c = 'a';
        int i = 26;
        for(c = 'a'; c <= 'z'; c++) {
            mp[c] = i;
            i--;
        }
        int ans = 0;
        i = 1;
        for(char ch : s) {
            ans += (mp[ch] * i);
            i++;
        }
        return ans;
    }
};