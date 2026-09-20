class Solution {
   public:
    int bfs(vector<vector<int>>& grid, vector<vector<bool>>& vis, int row, int col, int rows,
            int cols) {
        vis[row][col] = true;

        queue<pair<int, int>> q;
        q.push({row, col});

        int perimeter = 0;

        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for (int k = 0; k < 4; k++) {
                int nrow = r + delRow[k];
                int ncol = c + delCol[k];

                if (nrow < 0 || nrow >= rows || ncol < 0 || ncol >= cols) {
                    perimeter++;
                } else if (grid[nrow][ncol] == 0) {
                    perimeter++;
                } else if (!vis[nrow][ncol]) {
                    vis[nrow][ncol] = true;
                    q.push({nrow, ncol});
                }
            }
        }

        return perimeter;
    }


    int islandPerimeter(vector<vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();

    vector<vector<bool>> vis(rows, vector<bool>(cols, false));

    int perimeter = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == 1) {
                return bfs(grid, vis, i, j, rows, cols);
            }
        }
    }
    return perimeter;
}
}
;