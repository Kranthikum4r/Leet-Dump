class Solution {
public:
    bool rotateString(string s, string goal) {
        return (s + s).find(goal) ;
    }
};