class Solution {
   public:
    vector<vector<int>> dirs = {{1, 0}, {0, -1}, {0, 1}, {-1, 0}};

    bool possible(int t, int i, int j, vector<vector<int>>& grid, vector<vector<bool>>& vis) {
        int n = grid.size();
        if (i < 0 || i >= n || j < 0 || j >= n || vis[i][j] == true || grid[i][j] > t) return false;

        vis[i][j] = true;
        if (i == n - 1 && j == n - 1) return true;

        for (auto& dir : dirs) {
            int ni = i + dir[0];
            int nj = j + dir[1];

            if (possible(t, ni, nj, grid, vis)) {
                return true;
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
