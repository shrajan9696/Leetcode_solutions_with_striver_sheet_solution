class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<bool>> vis (n,vector<bool> (n,false));
        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> dis(n,vector<int> (n,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j] == 1) {
                    q.push({{i,j},0});
                    dis[i][j] = 0;
                    vis[i][j] = true;
                }
            }
        }
        
        while(!q.empty())
        {
            auto u = q.front();
            q.pop();
            int row = u.first.first;
            int col = u.first.second;
            int dist = u.second;
            int delrow[] = {-1,0,1,0};
            int delcol[] = {0,1,0,-1};
            for(int i=0;i<4;i++)
            {
                int nrow = row+delrow[i];
                int ncol = col+delcol[i];
                if(nrow>=0 and nrow<n and ncol>=0 and ncol<n and vis[nrow][ncol] == false and grid[nrow][ncol]==0){
                    q.push({{nrow,ncol},dist+1});
                    dis[nrow][ncol] = dist+1;
                    vis[nrow][ncol] = true;
                }
            }
            
        }
        int ans=-1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++){
                if(grid[i][j] == 0) ans = max(ans,dis[i][j]);
            }
        }
        if(ans==-1 or ans==0) return -1;
        else return ans;
    }
    
    
};