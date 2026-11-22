class Solution {
public:
    bool checkString(string s) {
        int lastA = -1, firstB = -1;
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == 'a') {
                if(firstB != -1 && i > firstB) 
                    return false;
            }
            else if(firstB == -1) {
                firstB = i;
            }
        }

        if(lastA == -1 || firstB == -1 || lastA < firstB) return true;
        return false;
    }
};