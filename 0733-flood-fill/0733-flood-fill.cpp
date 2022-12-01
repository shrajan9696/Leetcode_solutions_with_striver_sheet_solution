class Solution {
public:
    
       void BFS(vector<vector<int>>&image,int r,int c, int color,vector<vector<bool>>&visited)
    {
        int n = image.size();
        int m = image[0].size();
        queue<pair<int,int>> q;
        q.push({r,c});
        visited[r][c] = false;
        while(!q.empty()){
            auto u = q.front();
            q.pop();
            int row = u.first;
            int column = u.second;
            int x = image[row][column];
            image[row][column] = color;
            if(row-1>=0 and image[row-1][column] == x and visited[row-1][column] == false){
                visited[row-1][column] = true;
                q.push({row-1,column});
            }
            if(row+1<n and image[row+1][column] == x and visited[row+1][column] == false){
                visited[row+1][column] = true;
                q.push({row+1,column});
            }
              if(column-1>=0 and image[row][column-1] == x and visited[row][column-1] == false){
                visited[row][column-1] = true;
                q.push({row,column-1});
            }
            if(column+1<m and image[row][column+1] == x and visited[row][column+1] == false){
                visited[row][column+1] = true;
                q.push({row,column+1});
            }
        }
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
          int n = image.size();
        int m = image[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m, false));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++){
                visited[i][j] = false;
            }
        }
        BFS(image,sr,sc,newColor,visited);
        return image;
    }
};