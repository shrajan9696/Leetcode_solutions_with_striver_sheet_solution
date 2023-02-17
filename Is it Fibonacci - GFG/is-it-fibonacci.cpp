//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long solve(int N, int K, vector<long long> GeekNum) {
        // code here
        if(N<=K) return GeekNum[N-1];
        long long int sum=0;
        for(int i=0;i<K;i++) sum+=GeekNum[i];
        GeekNum.push_back(sum);
        int rem = N-K-1;
        int p=0;
        for(int i=0;i<rem;i++){
            sum = sum-GeekNum[p];
            sum+=GeekNum.back();
           GeekNum.push_back(sum);
           p++;
        }
        return GeekNum.back();
        
        
    }
};


//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;

        vector<long long> GeekNum(K);

        for (int i = 0; i < K; i++) cin >> GeekNum[i];

        Solution ob;
        cout << ob.solve(N, K, GeekNum) << "\n";
    }
    return 0;
}

// } Driver Code Ends