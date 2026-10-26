class Solution {
    int m, n;

    long long closed(vector<vector<int>>& grid, int i, int j) {
        if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0)
            return 0;

        long long val = grid[i][j];
        grid[i][j] = 0; // avoid re-visiting values

        val += closed(grid, i + 1, j);
        val += closed(grid, i, j + 1);
        val += closed(grid, i - 1, j);
        val += closed(grid, i, j - 1);

        return val;
    }
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        m = grid.size(), n = grid[0].size();

        int count = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] > 0) {
                    long long sum = closed(grid, i, j);

                    if(sum % k == 0)
                        count++;
                }
            }
        }
        
        return count;
    }
};