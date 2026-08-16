class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int f[3] = {0, 0, 0};

        for(int s : stones)
            f[s % 3]++;

        if(~f[0] & 1) // even no. of 0-stones
            return min(f[1], f[2]) >= 1; // should be atleast one of each

        return abs(f[1] - f[2]) >= 3; // 1 -> 1 -> 1
    }
};