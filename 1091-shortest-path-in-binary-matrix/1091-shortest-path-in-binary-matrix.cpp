class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<bool>> visited(n,vector<bool>(n,false));
        vector<vector<int>> dis(n,vector<int>(n,0));
        if(grid[0][0] == 1 or grid[n-1][n-1]==1) return -1;
        queue<pair<int,int>> q;
        q.push({0,0});
          visited[0][0] = true;
        dis[0][0] = 1;
        while(!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
          
            int delrow[]={-1,-1,-1,0,1,1,1,0};
            int delcol[]={-1,0,1,1,1,0,-1,-1};
            for(int i=0;i<8;i++){
                int nrow = delrow[i]+row;
                int ncol = delcol[i]+col;
                if(nrow>=0 and nrow<n and ncol>=0 and ncol<n and visited[nrow][ncol]==false and grid[nrow][ncol]==0){
                    q.push({nrow,ncol});
                    dis[nrow][ncol] = dis[row][col]+1;
                    visited[nrow][ncol] = true;
                }
            }
            
        }
        if(dis[n-1][n-1]==0) return -1;
        return dis[n-1][n-1];
    }
};