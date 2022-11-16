//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int beautySum(string s) {
        // Your code goes here
        int ans=0;
        
        for(int i=0;i<s.length();i++){
            int mx =1;
            map<int,int> m;
            int arr[26] ={0};
            for(int j=i;j<s.length();j++){
                
                int mn = INT_MAX;
                m[s[j]]++;
                arr[s[j]-'a']++;
                mx = max(mx,m[s[j]]);
               
               for(int k=0;k<26;k++ ){
                   if(arr[k]!=0){
                   mn = min(mn,arr[k]);
                   }
               }
                // for(auto x: m){
                //     mn = min(mn,x.second);
                // }
                //  cout<<mx<<" "<<mn<<" ";
                ans+=(mx-mn);
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
        string s;
        cin >> s;
        Solution obj;
        cout << obj.beautySum(s) << endl;
    }
    return 0;
}
// } Driver Code Ends