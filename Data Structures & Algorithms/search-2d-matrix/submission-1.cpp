class Solution {
   public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = 0;

        while (row < matrix.size()) {
            if (matrix[row][0] <= target &&
                target <= matrix[row][matrix[row].size() - 1]) {
                int colL = 0;
                int colH = matrix[row].size() - 1;
                while (colL <= colH) {
                    int m = colL + (colH - colL) / 2;
                    if (matrix[row][m] == target) {
                        return true;
                    } else if (matrix[row][m] < target) {
                        colL = m + 1;
                    } else {
                        colH = m - 1;
                    }
                }
            }
                row++;
            
        }
            return false;
        }
    };
