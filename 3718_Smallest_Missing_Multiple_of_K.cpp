class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> s(nums.begin(), nums.end());
        
        int i = k;
        while(true) {
            if(!s.count(k)) return k;
            k += i;
        }
        return k;
    }
};