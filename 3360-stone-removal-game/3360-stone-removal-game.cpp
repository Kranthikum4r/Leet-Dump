class Solution {
public:
    bool canAliceWin(int n) {
        int i = 10, k = 0;
        while(n >= i) {
            n -= i;
            i--;
            k++;
        }

        return k % 2 == 1;
    }
};