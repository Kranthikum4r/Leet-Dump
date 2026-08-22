class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();

        sort(bloomDay.begin(), bloomDay.end());
        
        int req = m * k;
        if(n < req) return -1;
        if(n == req) return bloomDay.back();

        int l = 0, h = n - 1;
        while(l <= h) {
            int mid = l + (h - l) / 2;

            if(mid + 1 == req) return bloomDay[mid];
            else if(mid + 1 < req)
                l = mid + 1;
            else
                h = mid - 1;;
        }
        return -1;
    }
};