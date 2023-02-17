//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
   bool isCapable(int nums[],int ans,int days,int n){
        long long int sum=0;
        int curr = 1;
        
        for(int i=0;i<n;i++){
            if(nums[i]>ans) return false;
            if(sum+nums[i]>ans){
                sum = nums[i];
                curr = curr+(nums[i]/ans);
                if(nums[i]%ans!=0) curr++;
                // curr++;
            }
            else sum+=nums[i];
        }
        return curr<=days;
    }
    int leastWeightCapacity(int weights[], int N, int days) {
        // code here
        long long int sum=0;
        for(int i=0;i<N;i++) sum+=weights[i];
        long long int low = 1;
        long long int high = sum;
        int res = sum;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(isCapable(weights,mid,days,N)){
             res=mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        return res;
    
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,D;
        cin>>N;
        
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];
        cin>>D;

        Solution ob;
        cout << ob.leastWeightCapacity(arr,N,D) << endl;
    }
    return 0;
}
// } Driver Code Ends