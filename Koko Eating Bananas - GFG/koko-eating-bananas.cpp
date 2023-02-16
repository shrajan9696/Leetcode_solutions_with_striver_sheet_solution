//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
   bool isValid(vector<int> piles,int ans,int h){
        long long int curr = 0;
        for(int i=0;i<piles.size();i++){
            curr+=(piles[i]/ans);
            if(piles[i]%ans!=0) curr++;
        }
        return (curr<=h);
    }
    int Solve(int N, vector<int>& piles, int h) {
        // Code here
         long long int low=1;
        long long int high = *max_element(piles.begin(),piles.end());
        long long int res= high;
        while(low<=high){
            long long int mid = low + (high-low)/2;
            if(isValid(piles,mid,h)){
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
        int n;
        cin >> n;
        vector<int> a;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        int h;
        cin >> h;
        Solution obj;

        cout << obj.Solve(n, a, h);
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends