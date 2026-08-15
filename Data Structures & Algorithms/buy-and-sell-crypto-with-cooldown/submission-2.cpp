class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 1 || n == 0) return 0;
        vector<int> dp(prices.size(), 0);
        dp[0] = 0;
        dp[1] = max(0, prices[1] - prices[0]);

        for (int i = 2; i < n; i++) {
            dp[i] = dp[i - 1];
            for (int j = 0; j < i; j++) {
                int prev_profit = j >= 2 ? dp[j - 2] : 0;
                dp[i] = max(prices[i] - prices[j] + prev_profit, dp[i]);
            }
        }
        return dp[n - 1];
    }
};
