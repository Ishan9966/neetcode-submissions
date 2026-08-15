class Solution {
   public:
    bool dfs(vector<int>& nums, int curSum, int sum, int i, vector<vector<int>>& dp) {
        if (curSum == sum) return true;
        if (i >= nums.size()) return false;
        if (curSum > sum) return false;
        if (dp[i][curSum] != -1) return dp[i][curSum];
        bool take = dfs(nums, curSum + nums[i], sum, i + 1, dp);
        bool notTake = dfs(nums, curSum, sum, i + 1, dp);

        return dp[i][curSum] = take || notTake;
    }
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0) {
            return false;
        }
        vector<vector<int>> dp(nums.size(), vector<int>(sum/2 + 1, -1));

        int curSum = 0;
        return dfs(nums, curSum, sum / 2, 0, dp);
    }
};
