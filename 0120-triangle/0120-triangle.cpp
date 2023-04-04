class Solution {
public:
    int ans = INT_MAX;
    int solve(int i,int j,int n,int m, vector<vector<int>> triangles,  vector<vector<int>> dp){
        if(i==n-1){
            // ans = min(ans,triangles[i][j]);
            return dp[i][j] = triangles[i][j];
        }
        if(dp[i][j]!=-1) return dp[i][j]; 
        else return  dp[i][j] = min((triangles[i][j]+solve(i+1,j,n,m,triangles,dp)),(triangles[i][j] + solve(i+1,j+1,n,m,triangles,dp)));
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int m = triangle[n-1].size();
        vector<vector<int>> dp(n,vector<int> (m,-1));
        dp[0][0] = triangle[0][0];
        for(int i=1;i<n;i++){
            for(int j=0;j<triangle[i].size();j++){
                int up = INT_MAX;
                int up_left  = INT_MAX;
                if(j!=0 and j!=triangle[i].size()-1){
                    up = triangle[i][j] + dp[i-1][j];
                    up_left = triangle[i][j] + dp[i-1][j-1];
                }
                else if(j==0){
                         up = triangle[i][j] + dp[i-1][j];
                }
                else if(j==triangle[i].size()-1){
                       up_left = triangle[i][j] + dp[i-1][j-1];
                }
                dp[i][j] = min(up,up_left);
                
            }
        }
     
        int ans=INT_MAX;
        for(int i=0;i<m;i++){
            ans = min(ans,(dp[n-1][i]));
        }
        return ans;
        
    }
};