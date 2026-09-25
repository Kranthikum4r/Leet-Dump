class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int>, int> mp; // unordered_map doesn't work here because its key must be hashable
        // map does not need a hash function. (uses comparison-> '<')
        int ans = 0;

        for(int i = 0; i < grid.size(); i++) {
            mp[grid[i]]++;
        }

        for(int i = 0; i < grid[0].size(); i++) {
            vector<int> v;

            for(int j = 0; j < grid.size(); j++) {
                v.push_back(grid[j][i]);
            }

            ans += mp[v];
        }
        return ans;
    }
};