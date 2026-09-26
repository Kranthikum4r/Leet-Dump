class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size() != word2.size()) return false;

        unordered_map<char, int> mp;

        for(char c : word1) {
            mp[c]++;
        }

        for(char c : word2) {
            if(!mp.count(c)) return false;
        }

        return true;
    }
};