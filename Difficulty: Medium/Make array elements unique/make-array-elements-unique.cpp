class Solution {
  public:
    int minIncrements(vector<int>& arr) {
        // Code here
        sort(arr.begin(),arr.end());
        int ans=0;
        for(int i=1;i<arr.size();i++){
            if(arr[i]<=arr[i-1]){
                int newValue=arr[i-1]+1;
                ans+=newValue-arr[i];
                arr[i]=newValue;
            }
        }
        return ans;
    }
};