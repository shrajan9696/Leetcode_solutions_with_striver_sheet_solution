class Solution {
public:
      void DFS(vector<vector<int>>&image,int row,int column, int color,vector<vector<bool>>&visited,int scol,int drow[],int dcol[])
    {
      
        visited[row][column] = true;
       
          int n = image.size();
          int m = image[0].size();
          image[row][column] = color;
          
             for(int i=0;i<4;i++)
             {
                int nrow =row+drow[i];
                int ncol = column +dcol[i];
                if(nrow>=0 and nrow<n and ncol>=0 and ncol<m and visited[nrow][ncol]==false and image[nrow][ncol]==scol)
                {
                      DFS(image,nrow,ncol,color,visited,scol,drow,dcol);
                }
             }
    }
            
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int n = image.size();
        int m = image[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m, false));
        int drow[4] = {-1,0,1,0};
        int dcol[4] = {0,1,0,-1};
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++){
                visited[i][j] = false;
            }
        }
        int scol = image[sr][sc];
        DFS(image,sr,sc,newColor,visited,scol,drow,dcol);
        return image;
    }
};