class Solution {
public:
    bool canShipped(vector<int>& weights, int capacity, int days) {
        int reqDays = 0;
        for(int w : weights) {
            reqDays += (w + capacity - 1) / capacity;
            if(reqDays > days)
                return false;
        }
        return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int l = 1, h = *max_element(weights.begin(), weights.end());
        int ans;
        while(l <= h) {
            int mid = l + (h - l) / 2;

            if(canShipped(weights, mid, days)) {
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