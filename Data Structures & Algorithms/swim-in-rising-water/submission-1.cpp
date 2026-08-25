class Solution {
   public:
    vector<vector<int>> dirs = {{1, 0}, {0, -1}, {0, 1}, {-1, 0}};

    bool possible(int t, int i, int j, vector<vector<int>>& grid, vector<vector<bool>>& vis) {
        int n = grid.size();

        if (grid[i][j] > t) return false;
        vis[i][j] = true;

        queue<pair<int, int>> q;
        q.push({i, j});

        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
q.pop();
            if (r == n - 1 && c == n - 1) return true;

            for (auto& it : dirs) {
                int nr = r + it[0];
                int nc = c + it[1];

                if (nr < 0 || nr >= n || nc >= n || nc < 0 || vis[nr][nc] || grid[nr][nc] > t)
                    continue;

                q.push({nr,nc});
                vis[nr][nc]=true;
            }
        }
        return false;
    }

    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int l = grid[0][0], r = n * n - 1;
        int ans = 0;
        while (l <= r) {
            int m = l + (r - l) / 2;
            vector<vector<bool>> vis(n, vector<bool>(n, false));
            if (possible(m, 0, 0, grid, vis)) {
                ans = m;
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return ans;
    }
};
