class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;

        while(low < high) {
            int mid = low + (high - low) / 2;

            if(nums[mid] > nums[high])
                high = mid;
            else
                low = mid + 1;
        }
        return high; // converges to one element
    }
};