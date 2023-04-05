//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:

	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        int m = 1000000007;
         vector<vector<int>> dp(n+1,vector<int>(sum+1,0));
       for(int i=0;i<n+1;i++){
          dp[i][0] = 1; 
       }
       for(int i=1;i<=n;i++){
           for(int j=0;j<=sum;j++){
               int take = 0;
               int not_take = 0;
               if(j<arr[i-1]){
                   not_take = dp[i-1][j];
               } 
               else{
                   take = dp[i-1][j-arr[i-1]];
                   not_take = dp[i-1][j];
               }
               dp[i][j] = ((take%m) +( not_take%m))%m;
           }
       }
       return dp[n][sum];
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends