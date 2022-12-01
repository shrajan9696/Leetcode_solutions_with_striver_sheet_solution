//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:

    void DFS(vector<vector<int>>&image,int row,int column, int color,vector<vector<bool>>&visited,int scol,int drow[],int dcol[])
    {
      
        visited[row][column] = true;
       
          int n = image.size();
          int m = image[0].size();
            // int x = image[row][column];
            image[row][column] = color;
            // if(row-1>=0 and image[row-1][column] == scol and visited[row-1][column] == false)
            // {
            //     visited[row-1][column] = true;
            //     DFS(image,row-1,column,color,visited,scol);
            // }
            // if(row+1<n and image[row+1][column] == scol and visited[row+1][column] == false)
            // {
            //     visited[row+1][column] = true;
            //       DFS(image,row+1,column,color,visited,scol);
            // }
            // if(column-1>=0 and image[row][column-1] == scol and visited[row][column-1] == false)
            // {
            //     visited[row][column-1] = true;
            //     DFS(image,row,column-1,color,visited,scol);
            // }
            // if(column+1<m and image[row][column+1] == scol and visited[row][column+1] == false)
            // {
            //     visited[row][column+1] = true;
            //      DFS(image,row,column+1,color,visited,scol);
            // }
            for(int i=0;i<4;i++){
                int nrow =row+drow[i];
                int ncol = column +dcol[i];
                if(nrow>=0 and nrow<n and ncol>=0 and ncol<m and visited[nrow][ncol]==false and image[nrow][ncol]==scol){
                      DFS(image,nrow,ncol,color,visited,scol,drow,dcol);
                }
            }
            
        
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
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

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends