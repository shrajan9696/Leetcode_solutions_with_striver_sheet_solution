//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int minIteration(int N, int M, int x, int y){    
        // code here
        int count=0;
        vector<vector<int>> mat(N,vector<int> (M,0));
        mat[x-1][y-1] = 1;
        queue<pair<int,int>> q;
        q.push({x-1,y-1});
        int delrow[4] = {1,0,-1,0};
        int delcol[4] = {0,1,0,-1};
        while(q.empty()==false){
         int flag=0;
            int c=q.size();
            for(int i=0;i<c;i++){
                 int row= q.front().first;
            int col = q.front().second;
            q.pop();
            for(int j=0;j<4;j++){
                int nrow = delrow[j]+ row;
                int ncol = delcol[j]+col;
                if(nrow>=0 and nrow<N and ncol>=0 and ncol<M){
                    if(mat[nrow][ncol] == 0){
                        // cout<<nrow<<" "<<ncol<<"\n";
                        flag=1;
                        q.push({nrow,ncol});
                        mat[nrow][ncol] = 1;
                    }
                }
            }
            }
              if(flag==1) count++;
            // count++;
           
        }
        return count;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, M, x, y;
        cin >> N >> M;
        cin >> x >> y;
        
        Solution ob;
        cout << ob.minIteration(N, M, x, y) << endl;
    }
    return 0; 
} 
// } Driver Code Ends