class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
     // we will apply BFS
        int n = grid.size();
        int m= grid[0].size();
        vector<vector<bool>> vis(n,vector<bool> (m,false));
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++)
        {
            // visiting first row
            if(grid[0][i] == 1 and vis[0][i] == false)
            {
                vis[0][i] = true;
                q.push({0,i});
            }
            // visiting last row
            if(grid[n-1][i] == 1 and vis[n-1][i]==false){
                vis[n-1][i] = true;
                q.push({n-1,i});
            }
        }
        
         for(int i=0;i<n;i++)
        {
            // visiting first column
            if(grid[i][0] == 1 and vis[i][0] == false)
            {
                vis[i][0] = true;
                q.push({i,0});
            }
            // visiting last column
            if(grid[i][m-1] == 1 and vis[i][m-1]==false){
                vis[i][m-1] = true;
                q.push({i,m-1});
            }
        }
        
        while(!q.empty())
        {
            auto u = q.front();
            q.pop();
            int row  = u.first;
            int col = u.second;
            int delrow[4] = {-1,0,1,0};
            int delcol[4] = {0,1,0,-1};
            for(int i=0;i<4;i++)
            {
                int nrow = row+delrow[i];
                int ncol = col + delcol[i];
                if(nrow>=0 and nrow<n and ncol>=0 and ncol<m and grid[nrow][ncol] == 1 and vis[nrow][ncol] == false)
                {
                    vis[nrow][ncol] = true;
                    q.push({nrow,ncol});
                }
            }
            
        }
        
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(vis[i][j] == false and grid[i][j] == 1) ans++;
            }
        }
        
        return ans;
    }
};