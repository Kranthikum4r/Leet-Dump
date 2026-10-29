class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        // remove maximum time in a substring from total sum 
        int sum = 0;
        int n = colors.length();

        for(int i = 1; i < n; i++) {
            int maxi = 0;
            while(i < n && colors[i] == colors[i - 1]) {
                sum += neededTime[i - 1];
                maxi = max(maxi, neededTime[i - 1]);
                i++;
            }
            sum += neededTime[i - 1];
            maxi = max(maxi, neededTime[i - 1]);
            if(maxi != 0) sum -= maxi; // remove largest value balloon
        }
        return sum;
    }
};