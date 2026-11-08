class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> rowCounts(n, 0), colCounts(m, 0);

        vector<vector<int>> visited(m, vector<int>(n, false));
        for(int row = 0; row < m; row++) {
            for(int col = 0; col < n; col++) {
                if(grid[row][col]) {
                    rowCounts[col]++;
                    colCounts[row]++;
                }
            }
        }

        int ans = 0;
        for(int row = 0; row < m; row++) {
            for(int col = 0; col < n; col++) {
                if(grid[row][col]) {
                    ans += rowCounts[col] > 1 || colCounts[row] > 1;
                }
            }
        }

        return ans;
    }
};