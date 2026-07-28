class Solution {
   public:
    bool dfs(vector<vector<char>>& board, string& word, int row, int col, int count) {
        if (count == word.size()) {
            return true;
        }
        if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size() ||
            word[count]!=board[row][col]) {
            return false;
        }


        char temp = board[row][col];
        board[row][col] = '*';
        bool isFound = dfs(board, word, row + 1, col, count + 1) ||
                       dfs(board, word, row - 1, col, count + 1) ||
                       dfs(board, word, row, col + 1, count + 1) ||

                       dfs(board, word, row, col - 1, count + 1);

        
        board[row][col] =temp;

        return isFound;
    }

    bool exist(vector<vector<char>>& board, string word) { 
       for(int i=0;i<board.size();i++){
        for(int j=0;j<board[0].size();j++){
            if(dfs(board,word,i,j,0)){
                return true;
            }
        }
       }
       return false;
    }
};
