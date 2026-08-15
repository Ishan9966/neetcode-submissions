class Solution {
   public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        vector<pair<int, int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

        queue<pair<int, int>> q;

        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'O') {
                q.push({i, 0});
                board[i][0] = '#';
            }
        }
        for (int i = 0; i < m; i++) {
            if (board[0][i] == 'O') {
                q.push({0, i});
                board[0][i] = '#';
            }
        }
        for (int i = 0; i < m; i++) {
            if (board[n - 1][i] == 'O') {
                q.push({n - 1, i});
                board[n - 1][i] = '#';
            }
        }
        for (int i = 0; i < n; i++) {
            if (board[i][m - 1] == 'O') {
                q.push({i, m - 1});
                board[i][m - 1] = '#';
            }
        }

        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for (auto [dr, dc] : dirs) {
                int nr = r + dr;
                int nc = c + dc;

                if (nr < 0 || nc < 0 || nr >= n || nc >= m) continue;
                if (board[nr][nc] != 'O') continue;

                board[nr][nc] = '#';
                q.push({nr, nc});
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                else if (board[i][j] == '#')
                    board[i][j] = 'O';
            }
        }
    }
};
