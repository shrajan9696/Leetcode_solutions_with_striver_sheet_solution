//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:

    void BFS(vector<vector<int>>&image,int r,int c, int color,vector<vector<bool>>&visited)
    {
        int n = image.size();
        int m = image[0].size();
        queue<pair<int,int>> q;
        q.push({r,c});
        visited[r][c] = true;
        while(!q.empty()){
            auto u = q.front();
            q.pop();
            int row = u.first;
            int column = u.second;
            int x = image[row][column];
            image[row][column] = color;
            if(row-1>=0 and image[row-1][column] == x and visited[row-1][column] == false)
            {
                visited[row-1][column] = true;
                q.push({row-1,column});
            }
            if(row+1<n and image[row+1][column] == x and visited[row+1][column] == false)
            {
                visited[row+1][column] = true;
                q.push({row+1,column});
            }
            if(column-1>=0 and image[row][column-1] == x and visited[row][column-1] == false)
            {
                visited[row][column-1] = true;
                q.push({row,column-1});
            }
            if(column+1<m and image[row][column+1] == x and visited[row][column+1] == false)
            {
                visited[row][column+1] = true;
                q.push({row,column+1});
            }
        }
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
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