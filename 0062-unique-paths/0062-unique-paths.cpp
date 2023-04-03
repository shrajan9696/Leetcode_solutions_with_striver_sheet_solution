class Solution {
public:
    
    
    // solve using memoization
    
    // int solve(int r,int c,vector<vector<int>> dp){
    //     if(r==0 and c==0) return dp[r][c] = 1;
    //     if(dp[r][c]!=-1) return dp[r][c];
    //     int l=0;
    //     int right=0;
    //     if(r>0) l = solve(r-1,c,dp);
    //     if(c>0) right = solve(r,c-1,dp);
    //     return dp[r][c] =  l+right;
    // }
    int uniquePaths(int m, int n) {
        // using tabulation
        
        vector<vector<int>> dp(m,vector<int>(n,1));
       for(int i=1;i<m;i++){
           for(int j=1;j<n;j++){
               dp[i][j] = dp[i-1][j] + dp[i][j-1];
           }
       }
        return dp[m-1][n-1];
    }
};