//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
   bool isValid(vector<int> stalls,int ans,int k,int count){
       int n = stalls.size();
       int start = stalls[0];
       for(int i=1;i<n;i++){
           if(stalls[i]-start>=ans){
               count++;
               start = stalls[i];
           }
       }
       return (k<=count);
   }
    int solve(int n, int k, vector<int> &stalls) {
    
        // Write your code here
        sort(stalls.begin(),stalls.end());
        long long int low=1;
        long long int high = stalls.back() - stalls[0];
        long long res = INT_MIN;
        while(low<=high){
            long long int mid = low + (high-low)/2;
            int count=1;
            if(isValid(stalls,mid,k,count)) {
                res= mid;
                low = mid+1;
            }
            else high = mid-1;
        }
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends