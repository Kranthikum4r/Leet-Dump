class Solution {
public:
    bool canShipped(vector<int>& weights, int capacity, int days) {
        int reqDays = 1;
        int currentWeight = 0;

        for(int w : weights) {
            if(currentWeight + w > capacity) {
                reqDays++;
                currentWeight = 0;
            }

            currentWeight += w;

            if(reqDays > days)
                return false;
        }

        return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int l = *max_element(weights.begin(), weights.end());
        int h = 0;
    
        for(int w : weights) h += w;
        
        int ans = h;
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