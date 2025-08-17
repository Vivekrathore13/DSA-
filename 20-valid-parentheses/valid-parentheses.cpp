class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        stack<char> st; // Stack to keep track of opening brackets

        for (int i = 0; i < n; i++) {
            // If current character is an opening bracket, push it to stack
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                st.push(s[i]);
            } 
            else {
                // If stack is empty, then there's no matching opening bracket
                if (st.size() == 0) {
                    return false;
                } 
                else {
                    // Check if the top of stack matches the closing bracket
                    if ((st.top() == '(' && s[i] == ')') ||
                        (st.top() == '{' && s[i] == '}') ||
                        (st.top() == '[' && s[i] == ']')) {
                        st.pop(); // Valid match → pop the opening bracket
                    } 
                    else {
                        return false; // Mismatched bracket found
                    }
                }
            }
        }

        // If stack is empty at the end → all brackets matched correctly
        return st.size() == 0;
    }
};
