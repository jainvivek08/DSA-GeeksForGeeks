class Solution {
  public:
    void solve(stack<int>& st, stack<int>& ans){
        if(st.size()==0){
            return;
        }
        int x=st.top();
        st.pop();
        solve(st,ans);
        ans.push(x);
        st.push(x);
    }
    stack<int> cloneStack(stack<int>& st) {
        // code here
        stack<int>ans;
        solve(st,ans);
        return ans;
    }
};