//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int countTriplets(vector<int>nums){
	    // Code here.
	   int res=0;
	    int n = nums.size();
	    for(int i=0;i<n;i++)
	    {
	        int ans=0,ans1=0;
	      for(int k=i-1;k>=0;k--){
	          if(nums[k]<nums[i]) ans1++;
	      }
	      for(int j=i+1;j<n;j++){
	          if(nums[j]>nums[i]) ans++;
	      }
	      res+=(ans1*ans);
	     
	    
	       
	    }
	    return res;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)cin >> nums[i];
		Solution ob;
		int ans = ob.countTriplets(nums);
		cout << ans << "\n";
	}  
	return 0;
}
// } Driver Code Ends