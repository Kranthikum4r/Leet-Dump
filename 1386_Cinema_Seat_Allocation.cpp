class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        vector<unordered_set<int>> blocked(n);

        for(auto it : reservedSeats) {
            blocked[it[0]-1].insert(it[1]-1);
        }

        int ans = 0;
        for(int i = 0; i < n; i++) {
            int j = 1;
            while(j < 5) {
                if(blocked[i].count(j)) break;
                j++;
                if(j == 5) ans++;
            }
            j = 3;
            while(j < 7) {
                if(blocked[i].count(j)) break;
                j++;
                if(j == 7) ans++;
            }
            j = 5;
            while(j < 9) {
                if(blocked[i].count(j)) break;
                j++;
                if(j == 9) ans++;
            }
        }

        return ans;
    }
};