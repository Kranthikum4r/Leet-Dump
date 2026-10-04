class Solution {
public:
    bool solve(string& s, int i, stack<char>& st) {
        if(i == s.length()) {
            return st.empty();
        }
        if(s[i] == '(') {
            st.push(s[i]);

            bool result = solve(s, i+1, st);
        
            st.pop(); // backtrack

            return result;
        }
        else if(s[i] == ')') {
            if(st.empty())
                return false;

            st.pop();

            bool result = solve(s, i+1, st);

            st.push('('); // backtrack
            
            return result;
        }
        else {
            // '('
            st.push('(');

            bool a = solve(s, i + 1, st);

            st.pop(); // backtrack

            // ')'
            bool b = false;

            if(!st.empty()) {
                st.pop(); // empty

                b = solve(s, i + 1, st);

                st.push('(');   // backtrack
            }

            // empty
            bool c = solve(s, i+1, st);

            return a || b || c;
        }
    }
    bool checkValidString(string s) {
        stack<char> st;

        return solve(s, 0, st);
    }
};