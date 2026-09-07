class Solution {
public:

    int solve(int val1, int val2, char ch) {

        if(ch == '+')
            return val1 + val2;

        else if(ch == '*')
            return val1 * val2;

        else if(ch == '-')
            return val1 - val2;

        else if(ch == '/') {
            int ans = val1 / val2;

            if((val1 < 0) != (val2 < 0) && val1 % val2 != 0)
                ans--;

            return ans;
        }

        else if(ch == '^')
            return pow(val1, val2);

        return 0;
    }

    int evaluatePostfix(vector<string>& arr) {

        stack<int> st;

        for(int i = 0; i < arr.size(); i++) {

            if(arr[i] != "+" && arr[i] != "-" &&
               arr[i] != "*" && arr[i] != "/" &&
               arr[i] != "^") {

                st.push(stoi(arr[i]));
            }

            else {

                int val2 = st.top();
                st.pop();

                int val1 = st.top();
                st.pop();

                int ans = solve(val1, val2, arr[i][0]);

                st.push(ans);
            }
        }

        return st.top();
    }
};