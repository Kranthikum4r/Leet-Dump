class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();

        // Calculate free items received by activating each item type.
        vector<int> freeCount(n, 0);

        for(int i = 0; i < n; i++) {
            int factor = items[i][0];

            for(int j = 0; j < n; j++) {
                if(i != j && items[j][0] % factor == 0) {
                    freeCount[i]++;
                }
            }
        }

        // dp[b] = maximum number of items obtainable
        // using exactly b money (purchased copies + free copies).
        vector<int> dp(budget + 1, 0);

        for(int i = 0; i < n; i++) {
            int price = items[i][1];
            int bonus = freeCount[i];

            // Step 1: Buy the first copy of this item.
            // This activates its free-item benefit.
            for(int b = budget; b >= price; b--) {
                dp[b] = max(dp[b], dp[b - price] + 1 + bonus);
            }

            // Step 2: Buy additional copies of this item.
            // Additional copies do not generate more free items.
            for(int b = price; b <= budget; b++) {
                dp[b] = max(dp[b], dp[b - price] + 1);
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};