class Solution {
  public:
    string preToInfix(string &s) {
        // code here
        stack<string>st;
        for(int i=s.length()-1;i>=0;i--){
            if(isalnum(s[i])){
                st.push(string(1,s[i]));
            }else{
                string val1=st.top();
                st.pop();
                string val2=st.top();
                st.pop();
                string ans="("+val1+s[i]+val2+")";
                st.push(ans);
            }
        }
        return st.top();
    }
};