class Solution {
  public:
    vector<string> generateBinary(int n) {
        // code here
        vector<string>ans;
        for(int i=1;i<=n;i++){
            string s="";
            int x=i;
            while(x!=0){
                s+=(x%2 + '0');
                x/=2;
            }
            reverse(s.begin(), s.end());
            ans.push_back(s);
        }
        return ans;
    }
};