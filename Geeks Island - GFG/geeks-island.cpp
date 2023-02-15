//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{   
public:

void DFS(vector<vector<int>> &mat, vector<vector<bool>> &vis,int r,int c,int del_row[],int del_col[]){
    int n = mat.size();
    int m = mat[0].size();
    // if(r==-1 or c==-1) return true;
    vis[r][c] = true;
    for(int i=0;i<4;i++){
       
            int nrow = r+del_row[i];
            int ncol = c+del_col[i];
            if(nrow>=0 and nrow<n and ncol>=0 and ncol<m){
                if(mat[nrow][ncol]>=mat[r][c] and vis[nrow][ncol] == false ){
                    DFS(mat,vis,nrow,ncol,del_row,del_col);
                }
                // else if(vis[nrow][ncol] == true) vis[nrow][ncol] = true;
            }
            // else if(r==-1 or c==-1) vis[r][c] = true;
        
    }
}
    
    
    

    int water_flow(vector<vector<int>> &mat,int N,int M){
    // Write your code here.
    // for indian ocean;
    
    vector<vector<bool>> vis_ind (N, vector<bool>(M,false) );
     int del_row[] ={-1,0,1,0};
    int del_col[] = {0,1,0,-1};
    
    for(int i=0;i<M;i++) {
        if(vis_ind[0][i]==false){
        DFS(mat,vis_ind,0,i,del_row,del_col);
        }
    }
    for(int i=0;i<N;i++) {
          if(vis_ind[i][0]==false){ 
        DFS(mat,vis_ind,i,0,del_row,del_col);
          }
       
    }
   
  
    
    // for(int i=1;i<N;i++){
    //     for(int j = 1;j<M;j++)
    //     {
    //         if(vis_ind[i-1][j] == true and mat[i-1][j]<=mat[i][j]) vis_ind[i][j] = true;
    //         else if(vis_ind[i][j-1] == true and mat[i][j-1]<=mat[i][j]) vis_ind[i][j] = true;
    //     }
    // }
    // for arabian sea;
    
    vector<vector<bool>> vis (N, vector<bool>(M,false) );
    
    for(int i=0;i<M;i++) {
        if(vis[N-1][i]==false){ 
        DFS(mat,vis,N-1,i,del_row,del_col);
          }
    }
    for(int i=0;i<N;i++) {
        if(vis[i][M-1] == false){
         DFS(mat,vis,i,M-1,del_row,del_col);
        }
    }
   
    
    // for(int i=N-2;i>=0;i--){
    //     for(int j =M-2;j>=0;j--)
    //     {
    //         if(vis[i+1][j] == true and mat[i+1][j]<=mat[i][j]) vis[i][j] = true;
    //         else if(vis[i][j+1] == true and mat[i][j+1]<=mat[i][j]) vis[i][j] = true;
    //     }
    // }
    
    // answer calculation
    
    int ans=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            // cout<<vis[i][j]<<" ";
            if(vis[i][j] == true and vis_ind[i][j] == true) ans++;
        }
        // cout<<"\n";
    }
    return ans;
    }
};



//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<int>> mat(n, vector<int>(m));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin>>mat[i][j];
            }
        }
        Solution ob;
        cout << ob.water_flow(mat, n, m) << endl;
        
    }
}


// } Driver Code Ends