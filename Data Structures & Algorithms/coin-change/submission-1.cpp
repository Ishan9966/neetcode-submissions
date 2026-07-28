class Solution {
   public:
    int dfs(vector<int>& coins, int amount, int i) {
        if (i == 0) {
            if (amount % coins[0] == 0) return amount / coins[i];
            return 1e9;
        }

        int notTake = dfs(coins, amount, i - 1);
        int take = INT_MAX;

        if (coins[i] <= amount) take = 1 + dfs(coins, amount - coins[i], i);

        return min(take, notTake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int c = dfs(coins, amount, coins.size() - 1);
        if (c >= 1e9) return -1;
        return c;
    }
};
