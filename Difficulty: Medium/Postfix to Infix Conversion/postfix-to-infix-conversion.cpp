class Solution {
  public:
    string postToInfix(string &s) {
        // code here
        stack<string>st;
        for(int i=0;i<s.length();i++){
            if(isalnum(s[i])){
                st.push(string(1, s[i]));
            }else{
                string val2=st.top();
                st.pop();
                string val1=st.top();
                st.pop();
                string ans='('+val1+s[i]+val2+')';
                st.push(ans);
            }
        }
        return st.top();
    }
};