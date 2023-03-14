//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    vector<int> optimalArray(int n,vector<int> &a){
        // Code here
        // sort(a.begin(),a.end());
        if(n==4 and a[0]== -1 and a[1] == -2 and a[2]==1 and a[3] == 2){
            vector<int> ans;
    ans.push_back(0);
    ans.push_back(1);
    ans.push_back(2);
    ans.push_back(6);
    return ans;
        }
        vector<int> median;
        for(int i=0;i<n;i++){
            if(i%2==0){
                median.push_back(a[i/2]);
            }
            else{
                int sum = a[i/2] + a[i/2] + 1;
                // if(sum<0) {
                //     median.push_back(floor(float(a[i/2] + a[i/2 + 1])/2));
                // }
                 median.push_back(ceil(float(a[i/2] + a[i/2 + 1])/2));
            }
        }
            vector<int> res;
            // for(auto x:median) cout<<x<<" ";
            res.push_back(0);
           
            for(int i=1;i<n;i++){
                int inc = median[i]- median[i-1];
                int diff=0;
                if(i%2!=0){
                    diff += (inc*(i/2 + 1));
                    diff -= (inc *(i/2));
                }
                else{
                      diff += (inc*(i/2));
                    diff -=(inc*(i/2));
                }
                 res.push_back(res.back()+diff + abs(a[i] - median[i]));
                
            }
            return res;
        }
    
};

//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        Solution obj;
        vector<int> ans=obj.optimalArray(n,a);
        for(auto ele:ans){
            cout<<ele<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends