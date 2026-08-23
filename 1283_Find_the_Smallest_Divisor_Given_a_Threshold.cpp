class Solution {
public:
    // int result(vector<int>& nums, int k) {
    //     for(int num : nums) {
    //         sum += 1;
    //     }
    // }
    int smallestDivisor(vector<int>& nums, int threshold) {
        sort(nums.begin(), nums.end());
        
        int sum = 0;
        for(int num : nums) sum += num;

        int l = 0, h = nums.size() - 1;
        int ans;
        while(l <= h) {
            int mid = l + (h - l) / 2;

            if(sum / nums[mid] <= threshold) {
                ans = mid;
                h = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        return ans;
    }
};