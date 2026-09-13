class Solution {
public:

    int prio(char ch) {
        if(ch == '^') return 3;
        if(ch == '/' || ch == '*') return 2;
        return 1;
    }

    string solve(string val1, string val2, char ch) {
        string ans = "";

        ans += val2;
        ans += val1;
        ans.push_back(ch);

        return ans;
    }

    string infixToPostfix(string& s) {

        stack<string> val;
        stack<char> st;

        for(int i = 0; i < s.length(); i++) {

            // Operand
            if(isalnum(s[i])) {
                val.push(string(1, s[i]));
            }

            else {

                // IMPORTANT: ')' ko sabse pehle check karo
                if(s[i] == ')') {

                    while(!st.empty() && st.top() != '(') {

                        char ch = st.top();
                        st.pop();

                        string val1 = val.top();
                        val.pop();

                        string val2 = val.top();
                        val.pop();

                        string ans = solve(val1, val2, ch);

                        val.push(ans);
                    }

                    // '(' remove
                    if(!st.empty()) {
                        st.pop();
                    }
                }

                // '('
                else if(s[i] == '(') {
                    st.push(s[i]);
                }

                // Stack empty
                else if(st.empty()) {
                    st.push(s[i]);
                }

                // Top is '('
                else if(st.top() == '(') {
                    st.push(s[i]);
                }

                // Current operator has higher priority
                else if(prio(s[i]) > prio(st.top())) {
                    st.push(s[i]);
                }

                // Lower or equal priority
                else {

                    while(!st.empty() &&
                          st.top() != '(' &&
                          (prio(s[i]) < prio(st.top()) ||
                          (prio(s[i]) == prio(st.top()) &&
                           s[i] != '^'))) {

                        char ch = st.top();
                        st.pop();

                        string val1 = val.top();
                        val.pop();

                        string val2 = val.top();
                        val.pop();

                        string ans = solve(val1, val2, ch);

                        val.push(ans);
                    }

                    st.push(s[i]);
                }
            }
        }

        // Remaining operators
        while(!st.empty()) {

            char ch = st.top();
            st.pop();

            string val1 = val.top();
            val.pop();

            string val2 = val.top();
            val.pop();

            string ans = solve(val1, val2, ch);

            val.push(ans);
        }

        return val.top();
    }
};