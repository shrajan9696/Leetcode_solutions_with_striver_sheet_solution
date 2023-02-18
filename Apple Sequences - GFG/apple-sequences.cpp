//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int appleSequences(int n, int m, string arr){
        // code here 
        int start = 0;
        int end =0;
        int co=0;
        int ca=0;
        int res=0;
        while(start<n and end<n){
            if(arr[end]=='A') ca++;
            else co++;
            while(co>m){
                if(arr[start] == 'A') ca--;
                else co--;
                start++;
            }
            res = max(res,co+ca);
            end++;
        }
        return res;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, M;
        cin >> N >> M;
        string arr;
        cin >> arr;
        
        Solution ob;
        cout << ob.appleSequences(N, M, arr) << endl;
    }
    return 0; 
} 
// } Driver Code Ends