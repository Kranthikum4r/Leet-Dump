class Solution {
public:
    vector<long long> getDistances(vector<int>& arr) {
        int n = arr.size();
        vector<long long> ans(n, 0);

        unordered_map<int, vector<int>> mp;

        for(int i = 0; i < n; i++) {
            if(!mp.count(arr[i])) {
                mp[arr[i]] = {i};
            }
            else {
                mp[arr[i]].push_back(i);
            }
        }

        for(int i = 0; i < n; i++) {
            for(int j : mp[arr[i]]) {
                ans[i] += abs(i - j);
            }
        }
        return ans;
    }
};