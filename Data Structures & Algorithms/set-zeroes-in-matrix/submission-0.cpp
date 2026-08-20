class Solution {
   public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<int> rows;
        vector<int> cols;
        int n = matrix.size();
        int m = matrix[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) {
                    rows.push_back(i);
                    cols.push_back(j);
                }
            }
        }

        for (auto& row : rows) {
            for (int i = 0; i < m; i++) {
                matrix[row][i] = 0;
            }
        }
        for (auto& col : cols) {
            for (int i = 0; i < n; i++) {
                matrix[i][col] = 0;
            }
        }
    }
};
