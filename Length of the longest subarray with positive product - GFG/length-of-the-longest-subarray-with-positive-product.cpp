//{ Driver Code Starts
//Initial Template for C++



#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
        // Function to return the length of the
        //longest subarray with ppositive product
        int maxLength(vector<int> &arr,int n){
           //code here
           for(int i=0;i<n;i++){
               if(arr[i]>0) arr[i] = 1;
               else if(arr[i]<0) arr[i] = -1;
           }
           int start = 0;
           int end = n-1;
           int l = 0;
           int ans = INT_MIN;
          long long int cpod = 1;
          
          for(int i=0;i<n;i++)
          {
              
              cpod = cpod*(arr[i]);
             if(cpod>0){
                 l = max(l,(i-start+1));
             }
             if(cpod==0)
             {
                 cpod=1;
                 start = i+1;
             }
          }
          cpod = 1;
           for(int i=n-1;i>=0;i--)
          {
              cpod = cpod*(arr[i]);
             if(cpod>0){
                 l = max(l,(end-i+1));
             }
             if(cpod==0)
             {
                 cpod=1;
                 end = i-1;
             }
          }
          return l;
        }
};

//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<int> arr(n);
	    for(int i = 0;i<n;i++){
	        cin>>arr[i];
	    }
	    Solution ob;
	    int res = ob.maxLength(arr,n);
	    cout<<res<<"\n";
	}
	return 0;
}
// } Driver Code Ends