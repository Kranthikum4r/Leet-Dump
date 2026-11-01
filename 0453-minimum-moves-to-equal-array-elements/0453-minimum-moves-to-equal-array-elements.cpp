class Solution {
public:
    int minMoves(vector<int>& nums) {
        // Raising n-1 elements by 1 is the same, relative to the other element, as lowering that single remaining element by 1.
        // imagine bringing down every element to min
        // sum - n * min

        return accumulate(nums.begin(), nums.end(), 0) - nums.size() * *min_element(nums.begin(), nums.end());
    }
};