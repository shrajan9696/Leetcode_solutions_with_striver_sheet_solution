//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int maxInstance(string s){
        map<char,int> m;
        for(int i=0;i<s.length();i++)
        {
            m[s[i]]++;
        }
        // m['l'] = ceil(float(m['l'])/2);
        // m['o'] = ceil(float(m['o'])/2);
        m['l'] = m['l']/2;
        m['o'] = m['o']/2;
        int ans=0;
        
        ans = min(m['l'],m['o']);
        ans = min(ans,m['b']);
        ans = min(ans,m['a']);
        ans = min(ans,m['n']);
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.maxInstance(s)<<endl;
    }
    return 0;
}
// } Driver Code Ends