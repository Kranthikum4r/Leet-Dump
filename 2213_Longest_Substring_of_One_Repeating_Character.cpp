class Solution {
public:
    int longest(string s) {
        int len = 1, maxlen = INT_MIN;
        for(int i = 1; i < s.size(); i++) {
            if(s[i] == s[i-1]) {
                len++;
            }
            else {
                maxlen = max(maxlen, len);
                len = 1;
            }
        }
        maxlen = max(maxlen, len);
        return maxlen;
    }
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        vector<int> ans(queryIndices.size());
        for(int i : queryIndices) {
            s[i] = queryCharacters[i];
            ans.push_back(longest(s));
        }
        return ans;
    }
};