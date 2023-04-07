class Solution {
public:
    int numDistinct(string s, string t) {
          int m = s.length();
        int n = t.length();
        int M=1e9+7;
        vector<vector< long long int>> dp(m+1,vector< long long int>(n+1,0));
       
        for(int i=0;i<=n;i++){
            dp[0][i] = 0;
        }
         for(int i=0;i<=m;i++) dp[i][0] = 1;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1] == t[j-1]){
                    dp[i][j] = dp[i-1][j-1]%M+dp[i-1][j]%M;
                }
                else dp[i][j] =dp[i-1][j]%M;
            }
        }
        return dp[m][n];
        
    }
};