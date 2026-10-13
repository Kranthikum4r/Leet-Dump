class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int prev = prices[0];

        for(int x : prices) {
            if(x > prev) profit += (x - prev);
            prev = x;
        }

        return profit;
    }
};