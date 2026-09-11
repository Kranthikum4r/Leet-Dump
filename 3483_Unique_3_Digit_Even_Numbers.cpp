class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int n = digits.size();
        unordered_set<int> st;

        for(int i = 0; i < n; i++) {
            if(digits[i] % 2 != 0)
                continue;

            for(int j = 0; j < n; j++) {
                // j = hundreds digit
                if(i == j)
                    continue;

                if(digits[j] == 0)
                    continue;

                for(int k = 0; k < n; k++) {
                    // k = tens digit
                    if(i == k || j == k)
                        continue;
                    
                    int num = digits[j] * 100 +
                              digits[k] * 10 +
                              digits[i];

                    st.insert(num);
                }
            }
        }
        return st.size();
    }
};