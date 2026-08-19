class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        vector<unordered_set<int>> blocked(n);

        for(auto it : reservedSeats) {
            blocked[it[0]-1].insert(it[1]-1);
        }

        int ans = 0;
        for(int i = 0; i < n; i++) {
            bool left = true;
            bool middle = true;
            bool right = true;

            for(int j = 1; j <= 4; j++) {
                if (blocked[i].count(j)) {
                    left = false;
                    break;
                }
            }

            for(int j = 3; j <= 6; j++) {
                if(blocked[i].count(j)) {
                    middle = false;
                    break;
                }
            }     

            for(int j = 5; j <= 8; j++) {
                if(blocked[i].count(j)) {
                    right = false;
                    break;
                }
            }

            if(left && right) {
                ans += 2;
            }
            else if(left || middle || right) {
                ans += 1;
            }   
        }
        return ans;
    }
};