//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	vector<int> findSubarray(int a[], int n) {
	    // code here
	  
	    vector<int> v;
	    int sum=0;
	    vector<pair<int,vector<int>>> ans;
	    for(int i=0;i<n;i++)
	    {
	        if(a[i]>=0){
	            sum+=a[i];
	            v.push_back(a[i]);
	        }
	        else{
	            if(v.size()>0){
	               // v.push_back(sum);
	                ans.push_back({sum,v});
	               v.clear();
	               
	                
	            }
	            sum=0;
	        }
	    }
	    if(a[n-1]>=0){
	        ans.push_back({sum,v}); 
	    }
	    sort(ans.begin(),ans.end());
	    reverse(ans.begin(),ans.end());
	   // int pos=0;
	   // for(int i=1;i<ans.size();i++)
	   // {
	   //     if(ans[i]<ans[i-1]){
	   //         pos = i-1;
	   //         break;
	   //     }
	   //     else
	   //     {
	            
	   //     }
	   // }
	   vector<int> x;
	   x.push_back(-1);
	   if(ans.size()==0) return x;
	   return ans[0].second;
	}
};

//{ Driver Code Starts.

void printAns(vector<int> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findSubarray(a, n);
        printAns(ans);
    }
    return 0;
}

// } Driver Code Ends