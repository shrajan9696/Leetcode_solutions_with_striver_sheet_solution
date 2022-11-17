//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

#define ll long long


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	// #define ll long long

	ll countSubarray(int arr[], int n, int k) {
	    // code here
	    vector<int> v;
	    if(arr[n-1]>k) v.push_back(n-1);
	    else v.push_back(-1);
	    for(int i=n-2;i>=0;i--)
	    {
	         if(arr[i]>k) v.push_back(i);
	        else v.push_back(v.back());
	    }
	    reverse(v.begin(),v.end());
	    long long int ans=0;
	    for(int i=0;i<v.size();i++){
	     if(v[i]!=-1){
	         ans+=(n-v[i]);
	     }   
	    }
	    return ans;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.countSubarray(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends