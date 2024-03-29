//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n = arr.size();
        
       vector<vector<bool>> dp(n+1,vector<bool>(sum+1,false));
       for(int i=0;i<n+1;i++){
          dp[i][0] = true; 
       }
       for(int i=1;i<=n;i++){
           for(int j=0;j<=sum;j++){
               bool take = false;
               bool not_take = false;
               if(j<arr[i-1]){
                   not_take = dp[i-1][j];
               } 
               else{
                   take = dp[i-1][j-arr[i-1]];
                   not_take = dp[i-1][j];
               }
               dp[i][j] = take or not_take;
           }
       }
       return dp[n][sum];
       

    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends