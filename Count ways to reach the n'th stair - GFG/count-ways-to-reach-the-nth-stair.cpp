//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to count number of ways to reach the nth stair.
    int countWays(int n)
    {
        // your code here
        int m = 1000000007;
        long long int prev = 1;
        long long int prev2= 1;
        long long int curr = 1;
        for(int i=2;i<=n;i++){
           curr = (prev%m+prev2%m)%m;
           prev2 = prev;
           prev = curr;
        }
        return curr;
    }
};



//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking stair count
        int m;
        cin>>m;
        Solution ob;
        cout<<ob.countWays(m)<<endl; // Print the output from our pre computed array
    }
    return 0;
}

// } Driver Code Ends