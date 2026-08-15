class Solution {
   public:
    int bfs(int row, int col, vector<vector<int>>& vis, vector<vector<int>>& grid, int n, int m) {
        vis[row][col] = 1;
        queue<pair<int, int>> q;
        q.push({row, col});
        int area=1;
        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            int delRow[] = {-1, 0, 1, 0};
            int delCol[] = {0, 1, 0, -1};

            for (int k = 0; k < 4; k++) {
                int nrow = row + delRow[k];
                int ncol = col + delCol[k];

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1 &&
                    !vis[nrow][ncol]) {
                    vis[nrow][ncol] = 1;
                    area++;
                    q.push({nrow, ncol});
                }
            }
        }
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        int maxi = -1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j] == 1) {
                    int area=bfs(i, j, vis, grid, n, m);
                    maxi=max(maxi,area);
                }
            }
        }
        return max(maxi,0);
    }
};
