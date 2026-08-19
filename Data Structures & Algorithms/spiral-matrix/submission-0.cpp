class Solution {
   public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int n = matrix.size();
        int m = matrix[0].size();
        int top = 0;
        int left = 0;
        int right = m - 1;
        int down = n - 1;

        int dir = 0;
        while (top<=down && left<=right) {
            if (dir == 0) {
                for (int i = left; i <= right; i++) {
                    ans.push_back(matrix[top][i]);
                }
                top++;
            }
            if (dir == 1) {
                for (int i = top; i <= down; i++) {
                    ans.push_back(matrix[i][right]);
                }
                right--;
            }
            if (dir == 2) {
                for (int i = right; i >= left; i--) {
                    ans.push_back(matrix[down][i]);
                }
                down--;
            }
            if (dir == 3) {
                for (int i = down; i >= top; i--) {
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }
            dir++;
            if(dir==4)dir=0;
        }
        return ans;
    }
};
