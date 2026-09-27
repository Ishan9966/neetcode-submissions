class Solution {
public:
    int helper(int n,vector<int>& dp){
       if(n==0)return 0;

       int minCount=INT_MAX;
        if(dp[n]!=-1)return dp[n];
       for(int i=1;i*i<=n;i++){
        int result=1+helper(n-i*i,dp);
        minCount=min(minCount,result);
       }
       return dp[n]=minCount;
    }
    int numSquares(int n) {
        vector<int> dp(n+1,-1);

        helper(n,dp);
        return dp[n];
    }
};