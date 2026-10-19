class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        int l = 0, h = nums.size() - 1;
        int first = -1, last = -1;
        while(l <= h) {
            int mid = l + (h - l) / 2;

            if(nums[mid] == target) {
                first = mid;
                h = mid - 1;
            }
            else if(nums[mid] < target) {
                l = mid + 1;
            }
            else {
                h = mid - 1;
            }
        }
        l = 0, h = nums.size() - 1;
        while(l <= h) {
            int mid = l + (h - l) / 2;

            if(nums[mid] == target) {
                last = mid;
                l = mid + 1;
            }
            else if(nums[mid] < target) {
                l = mid + 1;
            }
            else {
                h = mid - 1;
            }
        }

        vector<int> ans;
        if(first == -1) return ans;

        for(int i = first; i <= last; i++) {
            ans.push_back(i);
        }

        return ans;
    }
};