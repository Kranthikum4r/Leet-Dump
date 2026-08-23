class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        int half = n / 2;

        int leftSum = 0, rightSum = 0;
        int leftQ = 0, rightQ = 0;

        for(int i = 0; i < half; i++) {
            if(num[i] == '?')
                leftQ++;
            else
                leftSum += num[i] - '0';
        }

        for(int i = half; i < n; i++) {
            if(num[i] == '?')
                rightQ++;
            else
                rightSum += num[i] - '0';
        }

        // Key idea: compare the current sum diff with the maximum compensation possible from the remaining ? characters.
        return (leftSum - rightSum) != (rightQ - leftQ) * 9.0 / 2; // Alice wins
        // divided by 2 -> because the moves are split b/ w Alice & Bob
    }
};