class Solution {
public:
   int solve(int index,vector<int> dp){
       if(index==0) return  dp[index] = 1;
       
       if(index==1) return dp[index] =  1;
       if(dp[index]!=0) return dp[index];
       return dp[index] = solve(index-1,dp) + solve(index-2,dp);
   }
    int climbStairs(int n) {
         vector<int> dp(n+1,0);
         dp[0] = 1;
        dp[1] = 1;
        for(int i=2;i<=n;i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
        
        
    }
};