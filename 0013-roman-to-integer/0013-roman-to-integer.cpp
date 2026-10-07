class Solution {
public:
    int romanToInt(string s) {
        int prev = -1;

        unordered_map<char, int> mp;
        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;

        int ans = 0;
        for(int i = s.length() - 1; i >= 0; i--) {
            char c = s[i];

            if(mp[c] < prev) {
                ans -= mp[c];
            }
            else {
                ans += mp[c];
            }
            prev = mp[c];
        }
        return ans;
    }
};