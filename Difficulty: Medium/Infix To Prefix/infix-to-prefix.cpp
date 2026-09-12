class Solution {
  public:

    int prio(char ch) {
        if(ch == '^') return 3;
        else if(ch == '*' || ch == '/') return 2;
        else return 1;
    }

    string solve(string val1, string val2, char ch) {
        string s = "";

        s.push_back(ch);
        s += val1;
        s += val2;

        return s;
    }

    string infixToPrefix(string &s) {

        stack<string> val;
        stack<char> op;

        for(int i = 0; i < s.length(); i++) {

            // Operand
            // if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) {
            //     val.push(string(1, s[i]));
            // }
            // if(isalpha(s[i])) {
            //     val.push(string(1, s[i]));
            // }
            if(isalnum(s[i])) {
                val.push(string(1, s[i]));
            }

            else {

                // Stack empty
                if(op.size() == 0) {
                    op.push(s[i]);
                }

                // Opening bracket
                else if(s[i] == '(') {
                    op.push(s[i]);
                }

                // Closing bracket
                else if(s[i] == ')') {

                    while(op.top() != '(') {

                        char ch = op.top();
                        op.pop();

                        string val2 = val.top();
                        val.pop();

                        string val1 = val.top();
                        val.pop();

                        string ans = solve(val1, val2, ch);
                        val.push(ans);
                    }

                    if(!op.empty() && op.top() == '(') op.pop();// remove '('
                }
                
                else if(op.top() == '(') {
                    op.push(s[i]);
                }

                // Higher priority operator
                else if(prio(s[i]) > prio(op.top())) {
                    op.push(s[i]);
                }

                // Lower or equal priority
                else {

                    while(!op.empty() &&
                          op.top() != '(' &&
                          (prio(s[i]) < prio(op.top()) ||
                           (prio(s[i]) == prio(op.top()) && s[i] != '^'))) {

                        char ch = op.top();
                        op.pop();

                        string val2 = val.top();
                        val.pop();

                        string val1 = val.top();
                        val.pop();

                        string ans = solve(val1, val2, ch);
                        val.push(ans);
                    }

                    op.push(s[i]);
                }
            }
        }

        // Remaining operators
        while(op.size() > 0) {

            char ch = op.top();
            op.pop();

            string val2 = val.top();
            val.pop();

            string val1 = val.top();
            val.pop();

            string ans = solve(val1, val2, ch);
            val.push(ans);
        }

        return val.top();
    }
};