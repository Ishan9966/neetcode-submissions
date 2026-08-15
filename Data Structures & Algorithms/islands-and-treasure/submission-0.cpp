class Solution {
   public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if (n == 0) return;
        if (m == 0) return;

        queue<pair<int,int>> q;

        vector<pair<int,int>> dirs={{1,0},{-1,0},{0,1},{0,-1}};

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0) q.push({i,j});
            }
        }
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();

            for(auto it:dirs){
                int x=r+it.first;
                int y=c+it.second;

                if(x<0 ||y<0 ||x>=n|| y>=m ||grid[x][y]!=INT_MAX){
                     continue;
                }
                grid[x][y]=grid[r][c]+1;

                q.push({x,y});
            }
        }

    }
};
