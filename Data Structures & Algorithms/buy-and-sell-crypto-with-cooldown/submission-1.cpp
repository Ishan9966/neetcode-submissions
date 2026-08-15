class Solution {
   public:
    int solve(vector<int>& prices, int day, int n, bool buy,vector<vector<int>>& dp) {
        if (day >= n) return 0;
        int profit = INT_MIN;
        if(dp[day][buy]!=-1)return dp[day][buy];
        if (buy) {
            int take = solve(prices, day + 1, n, false,dp) - prices[day];
            int notTake = solve(prices, day + 1, n, true,dp);
            profit=max({profit,take,notTake});
        } else {
            int sell=solve(prices,day+2,n,true,dp)+prices[day];
            int notSell=solve(prices,day+1,n,false,dp);
            profit=max({profit,sell,notSell});
        }
        return dp[day][buy]=profit;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(5001,vector<int>(2,-1));
        return solve(prices, 0, n, true,dp);
    }
};
