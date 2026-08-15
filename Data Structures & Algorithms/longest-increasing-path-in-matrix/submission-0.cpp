class Solution {
   public:
    int dfs(int row, int col, vector<vector<int>>& matrix, vector<vector<int>>& dp) {
        vector<pair<int, int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

        if (dp[row][col] != -1) return dp[row][col];

        int l = 1;

        for (auto [dr, dc] : dirs) {
            int nr = row + dr;
            int nc = col + dc;
            if (nr < 0 || nr >= matrix.size() || nc < 0 || nc >= matrix[0].size()) continue;

            // must be strictly increasing
            if (matrix[nr][nc] <= matrix[row][col]) continue;

            l = max(l, 1 + dfs(nr, nc, matrix, dp));
        }
        return dp[row][col] = l;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        int maxi = INT_MIN;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                maxi = max(maxi, dfs(i, j, matrix, dp));
            }
        }
        return maxi;
    }
};
