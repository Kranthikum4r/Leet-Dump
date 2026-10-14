class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int smallest = arrays[0][0];
        int biggest = arrays[0].back();
        int max_dist = 0;

        for(int i = 1; i < arrays.size(); i++) {
            max_dist = max(max_dist, abs(arrays[i].back() - smallest));
            max_dist = max(max_dist, abs(biggest - arrays[i][0]));

            smallest = min(smallest, arrays[i][0]);
            biggest = max(biggest, arrays[i].back());
        }

        return max_dist;
    }
};