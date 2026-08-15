class Solution {
   public:
    int orangesRotting(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<pair<int, int>, int>> q;

        vector<pair<int, int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) q.push({{i, j}, 0});
            }
        }

        int time = 0;
        while (!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();
            for (auto [dr, dc] : dirs) {
                int nr = r + dr;
                int nc = c + dc;

                if (nr < 0 || nc < 0 || nr >= n || nc >= m) continue;

                if (grid[nr][nc] == 2) continue;
                if (grid[nr][nc] != 1) continue;

                grid[nr][nc] = 2;
                q.push({{nr, nc}, t + 1});
                time = max(time, t + 1);
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) return -1;
            }
        }

        return time;
    }
};
