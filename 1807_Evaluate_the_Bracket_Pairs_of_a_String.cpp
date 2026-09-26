class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> mp;
        string ans = "";

        for(auto& pair : knowledge) {
            mp[pair[0]] = pair[1];
        }

        int i = 0;
        int n = s.size();
        while(i < n) {
            if(s[i] == '(') {
                i++;
                string word = "";
                while(s[i] != ')') {
                    word += s[i];
                    i++;
                }
                if(!mp.count(word)) {
                    ans += '?';
                }
                else {
                    ans += mp[word];
                }
            }
            else {
                ans += s[i];
            }
            i++;
        }
        return ans;
    }
};