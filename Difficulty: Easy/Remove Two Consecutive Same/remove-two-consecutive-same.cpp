class Solution {
  public:
    int removeConsecutiveSame(vector<string>& arr) {
        // code here
        stack<string>st;
        for(int i=0;i<arr.size();i++){
            if(st.size()==0) st.push(arr[i]);
            else{
                if(st.top()==arr[i]){
                    st.pop();
                }
                else st.push(arr[i]);
            }
        }
        return st.size();
    }
};