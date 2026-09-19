class Solution {
  public:
    string preToPost(string &s) {
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
                string ans=val1+val2+s[i];
                st.push(ans);
            }
        }
        return st.top();
    }
};