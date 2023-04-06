class Solution {
public:
    // recursive solution
    
//     int solve(vector<int>& coins,int sum,int n){
       
        
//          if(n==0) {
//              if(sum==0) return 1;
//              else return 0;
//          }
//         if(sum==0) return 1;
//         if(sum<0) return 0;
//         return solve(coins,sum-coins[n-1],n) + solve(coins,sum,n-1);
        
//     }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
     
        vector<vector<int>> dp(n+1,vector<int>(amount+1,0));
        for(int i=0;i<=n;i++){
            dp[i][0] = 1;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=amount;j++){
                if(j<coins[i-1]) dp[i][j] = dp[i-1][j];
                else dp[i][j] = dp[i-1][j] + dp[i][j-coins[i-1]];
            }
        }
      return dp[n][amount];  
    }
};