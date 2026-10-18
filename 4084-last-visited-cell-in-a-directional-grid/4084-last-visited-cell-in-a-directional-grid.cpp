class Solution {
public:
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        set<pair<int, int>> visited;

        int x = 0, y = 0;
        visited.insert({x, y});

        while(true) {
            int nx = x, ny = y;

            char d = grid[x][y];

            if(d == 'L') {
                ny--;
            }
            else if(d == 'R') {
                ny++;
            }
            else if(d == 'U') {
                nx--;
            }
            else if(d == 'D') {
                nx++;
            }

            if(nx < 0 || nx >= m || ny < 0 || ny >= n) {
                return {x, y};
            }

            if(visited.count({nx, ny})) {
                return {x, y};
            }

            x = nx;
            y = ny;
            visited.insert({x, y});
        }

    }
};