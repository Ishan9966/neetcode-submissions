class Solution {
   public:
    int f(int i, int j, string& t, string& s, vector<vector<int>>& dp) {
        if (i < 0 || j < 0) return 0;
        if (dp[i][j] != -1) return dp[i][j];

        if (t[i] == s[j]) return dp[i][j] = 1 + f(i - 1, j - 1, t, s, dp);

        return dp[i][j] = max(f(i - 1, j, t, s, dp), f(i, j - 1, t, s, dp));
    }
    int longestCommonSubsequence(string t, string s) {
        int n = t.size();
        int m = s.size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        return f(n - 1, m - 1, t, s, dp);
    }
};
