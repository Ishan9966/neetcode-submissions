#include <limits.h>

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<unsigned long long> dp(amount + 1, 0);
        dp[0] = 1;

        for (int coin : coins) {
            for (int t = coin; t <= amount; t++) {
                if (dp[t] > ULLONG_MAX - dp[t - coin]) {
                    // Overflow would happen, handle accordingly
                    dp[t] = ULLONG_MAX;
                } else {
                    dp[t] += dp[t - coin];
                }
            }
        }

        return dp[amount] > INT_MAX ? -1 : dp[amount]; // safe cast
    }
};