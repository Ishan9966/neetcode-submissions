class Solution {
public:
    int dfs(vector<int>& nums, int i, int prev, vector<vector<int>>& dp) {

        if (i == nums.size())
            return 0;

        if (dp[i][prev + 1] != -1)
            return dp[i][prev + 1];

        int skip = dfs(nums, i + 1, prev, dp);

        int take = 0;

        if (prev == -1 || nums[i] > nums[prev])
            take = 1 + dfs(nums, i + 1, i, dp);

        return dp[i][prev + 1] = max(take, skip);
    }

    int lengthOfLIS(vector<int>& nums) {

        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(n + 1, -1));

        return dfs(nums, 0, -1, dp);
    }
};