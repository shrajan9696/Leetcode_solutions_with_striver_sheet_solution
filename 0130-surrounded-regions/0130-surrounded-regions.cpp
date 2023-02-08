class Solution {
public:
    void DFS(vector<vector<char>>& board,int row,int col,vector<vector<bool>> &vis,int delrow[],int delcol[])
    {
        int n = board.size();
        int m = board[0].size();
        vis[row][col] = true;
        for(int i=0;i<4;i++)
        {
            int nrow = row+delrow[i];
            int ncol = col + delcol[i];
            if(nrow>=0 and nrow<n and ncol>=0 and ncol<m and board[nrow][ncol] == 'O' and vis[nrow][ncol] == false){
                 DFS(board,nrow,ncol,vis,delrow,delcol);
            }
        }
        
        
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>> vis(n,vector<bool> (m,false));
        for(int j=0;j<m;j++)
        {
            if(board[0][j]=='O' and vis[0][j] == false)
            {
                int delrow[] = {-1,0,1,0};
                int delcol[] = {0,1,0,-1};
                DFS(board,0,j,vis,delrow,delcol);
            }
        }
        
          for(int j=0;j<m;j++)
        {
            if(board[n-1][j]=='O' and vis[n-1][j] == false)
            {
                int delrow[] = {-1,0,1,0};
                int delcol[] = {0,1,0,-1};
                DFS(board,n-1,j,vis,delrow,delcol);
            }
        }
        
         for(int j=0;j<n;j++)
        {
            if(board[j][0]=='O' and vis[j][0] == false)
            {
                int delrow[] = {-1,0,1,0};
                int delcol[] = {0,1,0,-1};
                DFS(board,j,0,vis,delrow,delcol);
            }
        }
        
         for(int j=0;j<n;j++)
        {
            if(board[j][m-1]=='O' and vis[j][m-1] == false)
            {
                int delrow[] = {-1,0,1,0};
                int delcol[] = {0,1,0,-1};
                DFS(board,j,m-1,vis,delrow,delcol);
            }
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(vis[i][j] == false and board[i][j] == 'O' ) board[i][j] = 'X';
            }
        }
       
    }
};