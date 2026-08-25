class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> s(nums.begin(), nums.end());
        
        int i = 2;
        while(true) {
            if(!s.count(k)) return k;
            k *= i;
            i++;
        }
        return -1;
    }
};