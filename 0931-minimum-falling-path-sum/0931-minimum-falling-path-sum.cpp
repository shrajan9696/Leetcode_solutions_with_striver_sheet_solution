class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& triangle) {
        int n = triangle.size();
          int m = triangle[n-1].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        for(int i=0;i<m;i++){
            dp[n-1][i] = triangle[n-1][i];
        }
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<m;j++){
                int up = INT_MAX;
                int ld = INT_MAX;
                int rd = INT_MAX;
                if(j!=0 and j!=m-1){
                    up = triangle[i][j] + dp[i+1][j];
                    ld = triangle[i][j] + dp[i+1][j-1];
                    rd = triangle[i][j] + dp[i+1][j+1];
                }
                else if(j==0){
                     up = triangle[i][j] + dp[i+1][j];
                     rd = triangle[i][j] + dp[i+1][j+1];
                }
                else if(j==(m-1)){
                     up = triangle[i][j] + dp[i+1][j];
                     ld = triangle[i][j] + dp[i+1][j-1];
                }
                dp[i][j] = min(up,min(ld,rd));
            }
        }
        int ans = INT_MAX;
        for(int i=0;i<n;i++){
            ans = min(ans,dp[0][i]);
        }
        return ans;
    }
};