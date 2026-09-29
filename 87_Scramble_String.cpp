class Solution {
public:
    bool isScramble(string s1, string s2) {
        int n = s1.length();

        vector<int> freq1(26, 0), freq2(26, 0);
        for(char c : s1) freq1[c - 'a']++;
        for(char c : s2) freq2[c - 'a']++;

        for(int i = 0; i < 26; i++) {
            if(freq1[i] != freq2[i]) return false;
        }

        for(int i = 0; i < n; i++) {
            if(s1[i] == s2[i]) return true;
        }

        return false;
    }
};