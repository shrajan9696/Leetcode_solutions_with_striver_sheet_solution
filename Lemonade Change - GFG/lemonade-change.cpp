//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool lemonadeChange(int N, vector<int> &bills) {
        // code here
        map<int,int> m;
        for(int i=0;i<bills.size();i++){
         if(bills[i]==5) {
             m[5]++;
         }
         else if(bills[i]==10){
             if(m[5]<=0) return false;
             else{
                 m[10]++;
                 m[5]--;
             }
         }
         else{
             if(m[10]>=1 and m[5]>=1){
                 m[20]++;
                 m[10]--;
                 m[5]--;
               
             }
             else if(m[5]>=3){
                   m[20]++;
                 // m[10]--;
                 m[5]--;
                  m[5]--;
                  m[5]--;
               
             }
             else return false;
             
         }
     }
        return true;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> bills(N);
        for (int i = 0; i < N; i++) cin >> bills[i];

        Solution obj;
        int ans = obj.lemonadeChange(N, bills);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends