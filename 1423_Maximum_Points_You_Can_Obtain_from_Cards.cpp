class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int score = 0;
        for(int i = 0; i < k; i++) {
            score += cardPoints[i];
        }

        int n = cardPoints.size();
        if(k == n) return score;

        int maxscore = score;
        for(int i = 0; i < k; i++) {
            score -= (cardPoints[k - i - 1]);
            score += (cardPoints[n - i - 1]);

            maxscore = max(maxscore, score);
        }

        return maxscore;
    }
};