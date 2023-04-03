//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int maximumPoints(vector<vector<int>>& points, int n) {
        // Code here
        vector<vector<int>> dp(n,vector<int>(3,0));
       
       
        for(int i=0;i<3;i++){
             dp[0][i] = points[0][i]; 
        }
        // for(int i=0;i<3;i++) dp[0][i] = mx;
        for(int i=1;i<n;i++){
            for(int j=0;j<=2;j++){
                if(j==0){
                    dp[i][j] = max((dp[i-1][1]+points[i][j]),(dp[i-1][2]+points[i][j]));
                }
                else if(j==1){
                      dp[i][j] = max((dp[i-1][0]+points[i][j]),(dp[i-1][2]+points[i][j]));
                }
                 else if(j==2){
                      dp[i][j] = max((dp[i-1][0]+points[i][j]),(dp[i-1][1]+points[i][j]));
                }
            }
        }
        int ans=0;
        for(int i=0;i<3;i++){
            ans = max(ans,dp[n-1][i]);
        }
        return ans;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> points;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            points.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(points, n) << endl;
    }
    return 0;
}
// } Driver Code Ends