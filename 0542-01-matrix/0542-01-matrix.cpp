class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
     vector<vector<int>> vis(n,vector<int> (m,0));
        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> dis(n,vector<int> (m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j] == 0) 
                {
                    dis[i][j] = 0;
                q.push({{i,j},0});
                vis[i][j] = 1;
                }
            }
        }
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};
        
        while(!q.empty())
        {
            
            auto u = q.front();
            q.pop();
            dis[ u.first.first][u.first.second] = u.second;
            for(int i=0;i<4;i++)
            {
                int nrow = u.first.first+delrow[i];
                int ncol = u.first.second + delcol[i];
                if(nrow>=0 and nrow<n and ncol>=0 and ncol<m and vis[nrow][ncol] ==0 and mat[nrow][ncol]==1)
                {
                    vis[nrow][ncol] = 1;
                    q.push({{nrow,ncol},dis[u.first.first][u.first.second]+1});
                    
                }
            }
            
        }
        return dis;
        
    }
};