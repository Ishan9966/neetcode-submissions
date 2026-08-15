class Solution {
   public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> ans;
        vector<vector<bool>> atlantic(n, vector<bool>(m, false));
        vector<vector<bool>> pacific(n, vector<bool>(m, false));
        queue<pair<int, int>> qp;
        queue<pair<int, int>> qa;
        vector<pair<int, int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        for (int i = 0; i < n; i++) {
            qp.push({i, 0});
            pacific[i][0] = true;
        }
        for (int i = 0; i < m; i++) {
            qp.push({0, i});
            pacific[0][i] = true;
        }
        for (int i = 0; i < m; i++) {
            qa.push({n - 1, i});
            atlantic[n - 1][i] = true;
        }
        for (int i = 0; i < n; i++) {
            qa.push({i, m - 1});
            atlantic[i][m - 1] = true;
        }

        while (!qp.empty()) {
            int r = qp.front().first;
            int c = qp.front().second;
            qp.pop();

            for (auto [dr, dc] : dirs) {
                int nr = r + dr;
                int nc = c + dc;

                if (nr < 0 || nc < 0 || nr >= n || nc >= m) continue;
                if (pacific[nr][nc]) continue;
                if (heights[r][c] > heights[nr][nc]) continue;

                pacific[nr][nc] = true;
                qp.push({nr, nc});
            }
        }
        while (!qa.empty()) {
            int r = qa.front().first;
            int c = qa.front().second;
            qa.pop();

            for (auto [dr, dc] : dirs) {
                int nr = r + dr;
                int nc = c + dc;

                if (nr < 0 || nc < 0 || nr >= n || nc >= m) continue;
                if (atlantic[nr][nc]) continue;
                if (heights[r][c] > heights[nr][nc]) continue;

                atlantic[nr][nc] = true;
                qa.push({nr, nc});
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }
};
