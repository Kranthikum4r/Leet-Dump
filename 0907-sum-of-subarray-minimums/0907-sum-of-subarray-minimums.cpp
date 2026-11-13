class Solution {
public:
    // Contribution = arr[i] * (i-PSE) * (NSE-i)

    int MOD = 1e9 + 7;
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();

        vector<int> left(n), right(n); // number of subarrays does element is minimum for
        stack<int> st;
    
        // strictly smaller previous element (PSE)
        for(int i = 0; i < n; i++) {
            while(!st.empty() && arr[st.top()] >= arr[i]) { // >= means do not consider equal elements also (strictly smaller)
                st.pop();
            }

            left[i] = st.empty() ? i + 1 : i - st.top();

            st.push(i);
        }

        while(!st.empty()) st.pop();

        // strictly smaller previous element (PSE)
        for(int i =  n - 1; i >= 0; i--) {
            while(!st.empty() && arr[st.top()] > arr[i]) { // > means consider equal elements also
            // this is to balance double counting
                st.pop();
            }

            right[i] = st.empty() ? n - i : st.top() - i;

            st.push(i);
        }

        long long ans = 0;

        for(int i = 0; i < n; i++) {
            long long contribution  = 
                (1LL * arr[i] * left[i] * right[i]) % MOD;

            ans = (ans + contribution) % MOD;
        }

        return ans;
    }
};