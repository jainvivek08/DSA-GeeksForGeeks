class Solution {
  public:
    int profit(vector<int>& arr) {
        // code here
        int ans=0;
        stack<int>st;
        for(int i=arr.size()-1;i>=0;i--){
            while(!st.empty() && st.top()<arr[i]){
                st.pop();
            }
            if(!st.empty()){
                ans+=abs(st.top()-arr[i]);
            }else{
                ans+=arr[i];
            }
            st.push(arr[i]);
        }
        return ans;
    }
};