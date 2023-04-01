//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
  bool solve(vector<vector<char>>& board,string word,int row,int col,int i, int delrow[],int delcol[],int n,int m){
        if(i>=word.size())
            return true;
        // if(board[row][col] !=word[i] or vis[row][col] == true) return false; 
     
            for(int x=0;x<4;x++){
                int nr = row+delrow[x];
                int nc = col+delcol[x];
                if( nr>=0 and nr<n and nc>=0 and nc<m  and board[nr][nc] == word[i] ){
                    // vis[nr][nc] = true;
                    board[nr][nc] = '*';
                    if(solve(board,word,nr,nc,i+1,delrow,delcol,n,m)) return true;
                    board[nr][nc] = word[i];
                }
            }
            return false;
          
    
    }
    bool isWordExist(vector<vector<char>>& board, string word) {
        // Code here
          int n = board.size();
        int m = board[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
         int delrow[4] = {-1,0,1,0};
         int delcol[4] = {0,1,0,-1};
        for(int i=0;i<n;i++){
         for(int j=0;j<m;j++){
             if(board[i][j] == word[0]){
                 board[i][j] = '*';
                 if(solve(board,word,i,j,1,delrow,delcol,n,m)) return true;
                 else board[i][j] = word[0];
             }
         }
     }

     return false;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}
// } Driver Code Ends