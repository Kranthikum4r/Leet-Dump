class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int n = digits.size();
        int ans = 0;

        for(int i = 0; i < n; i++) {
            if(digits[i] % 2 != 0)
                continue;

            for(int j = 0; j < n; j++) {
                if(i == j)
                    continue;

                if(digits[j] == 0)
                    continue;

                for(int k = 0; k < n; k++) {
                    if(i == k || j == k)
                        continue;
                    
                    ans++;
                }
            }
        }
        return ans;
    }
};