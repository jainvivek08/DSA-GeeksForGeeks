class Solution {
  public:
    vector<int> fibonacciNumbers(int n) {
        // code here
        vector<int>dp(n+1);
        dp[0]=0;
        dp[1]=1;
        for(int i=2;i<=n;i++){
            dp[i]=(dp[i-1]+dp[i-2]) % (1000000007);
        }
        return dp;
    }
};