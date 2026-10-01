class Solution {
public:
    bool isValid(string s) {
        stack<int> st;

        for(char c : s) {
            if(!st.empty() && c == ')') {
                return false;
            }
            if(c == '(' || c == '{' || c == '[') {
                st.push(c);
            }
            else if(
                (st.top() == '(' && c == ')') ||
                (st.top() == '{' && c == '}') ||
                (st.top() == '[' && c == ']')
            ) {
                st.pop();

            }
            else {
                return false;
            }
        }
        return st.empty();
    }
};