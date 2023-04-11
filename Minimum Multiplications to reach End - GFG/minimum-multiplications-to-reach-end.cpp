//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        int m = 100000;
        vector<int> dis(100000,INT_MAX);
        dis[start] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0,start});
        while(!pq.empty()){
            int v = pq.top().second;
            int d = pq.top().first;
            if(v==end) return d;
            pq.pop();
            for(int i=0;i<arr.size();i++){
                int node= ((v%m)*(arr[i]%m))%m;
                if(dis[node]>(d+1)){
                    dis[node] = d+1;
                    pq.push({dis[node],node});
                }
            }
        }
        if(dis[end] == INT_MAX) return -1;
        else return dis[end];
        
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends