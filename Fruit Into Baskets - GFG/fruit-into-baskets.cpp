//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int totalFruits(int N, vector<int> &fruits) {
        
        int start=0;
        int end=0;
        int n = fruits.size();
        int ans=0;
        map<int,int> m;
        while(start<n and end<n)
        {
            m[fruits[end]]++;
            if(m.size() <= 2)
            {
                ans = max(ans,(end-start+1));
            }
            else if(m.size()>2)
            {
                m[fruits[start]]--;
                if(m[fruits[start]]<=0) m.erase(fruits[start]);
                start++;
            }
            end++;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> fruits(N);
        for (int i = 0; i < N; i++) cin >> fruits[i];
        Solution obj;
        cout << obj.totalFruits(N, fruits) << endl;
    }
    return 0;
}

// } Driver Code Ends