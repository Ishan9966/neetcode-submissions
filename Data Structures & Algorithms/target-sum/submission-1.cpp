class Solution {
   public:
    int solve(vector<int>& nums, int target, int& count, int i, int sum, vector<vector<int>>& dp) {
        if (i >= nums.size()) {
            if (sum == target)
                return 1;
            else
                return 0;
        }
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        if (abs(target) > totalSum) return 0;
        if (dp[i][sum + totalSum] != -1) return dp[i][sum + totalSum];

        int positive = solve(nums, target, count, i + 1, sum + nums[i], dp);
        int negative = solve(nums, target, count, i + 1, sum - nums[i], dp);

        return dp[i][sum+totalSum] = positive + negative;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int count = 0;
        int sum = 0;
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        vector<vector<int>> dp(nums.size() + 1, vector<int>(2 * totalSum + 1, -1));
        return solve(nums, target, count, 0, sum, dp);
    }
};
