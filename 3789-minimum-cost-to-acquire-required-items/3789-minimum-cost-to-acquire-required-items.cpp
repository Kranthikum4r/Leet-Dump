class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long totalCost = 0;

        // if buying seperately is cheaper than item 3
        if(cost1 + cost2 <= costBoth) {
            totalCost = 1LL * cost1 * need1 + 1LL * cost2 * need2;
        }
        else {
            // buy item 3 min(need1, need2) times
            int cnt_3 = min(need1, need2);
            totalCost = 1LL * cnt_3 * costBoth;

            need1 -= cnt_3;
            need2 -= cnt_3;

            if(need1 > 0) {
                totalCost += 1LL * need1 * min(cost1, costBoth);
            }

            else if(need2 > 0) {
                totalCost += 1LL * need2 * min(cost2, costBoth);
            }
        }

        return totalCost;
    }
};