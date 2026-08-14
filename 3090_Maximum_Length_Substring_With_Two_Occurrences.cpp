class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.size();
        int res = 0;
        for(int left = 0; left < n; ++left) {
            vector<int> count(26, 0);
            for(int right = left; right < n; ++right) {
                int index = s[right] - 'a';
                count[index]++;
                if(count[index] > 2) {
                    break;
                }
                res = max(res, right - left + 1);
            }
        }
        return res;
    }
};