//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
  vector<vector<int>> answer;
   bool isSafe(int row,int col,int n,vector<string> board){
        int x = row;
        int y = col;
        while(row>=0 and col>=0){
            if(board[row][col] == 'Q'){
                return false;
            }
            row--;
            col--;
        }
        row=x;
        col = y;
        while(row<n and col>=0){
             if(board[row][col] == 'Q'){
                return false;
            }
            row++;
            col--;
        }
        row = x;
        col = y;
          while( col>=0){
             if(board[row][col] == 'Q'){
                return false;
            }
           
            col--;
        }
        return true;
        
        
    }
     void generate(vector<string> board,vector<vector<string>> &ans,int n,int col,vector<int> res){
        if(col==n){
            ans.push_back(board);
            answer.push_back(res);
            
            return ;
        }
        for(int row=0;row<n;row++){
            if(isSafe(row,col,n,board)){
                board[row][col] = 'Q';
                res.push_back(row+1);
                  generate(board,ans,n,col+1,res);
                board[row][col] = '.';
                res.pop_back();
                
            }
        }
    }
    vector<vector<int>> nQueen(int n) {
        // code here
         vector<vector<string>> ans;
        vector<string> board;
         string s="";
        for(int i=0;i<n;i++) s+='.';
        for(int i=0;i<n;i++) board.push_back(s);
        vector<int> res;
        generate(board,ans, n,0,res);
        return answer;
      
       
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends