class Solution {
  public:
    string postToPre(string s) {
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
                string ans=s[i]+val1+val2;
                st.push(ans);
            }
        }
        return st.top();
    }
};