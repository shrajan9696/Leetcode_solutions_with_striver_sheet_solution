//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int checkCompressed(string S, string T) {
        // code here
        int n = S.length();
        int m = T.length();
        long long int x=0;
        for(int i=0;i<m;){
            if(T[i]>='A' and T[i]<='Z'){
                if(T[i] == S[x]) x++;
                else return 0;
                i++;
            }
            else{
                string res="";
                while(i<m and T[i]>='0' and T[i]<='9'){
                    res+=T[i];
                   
                    i++;
                }
                 long long int num = stoi(res);
                    if((x+num)>n) return false;
                    x = x+num;
            }
            // cout<<x<<" ";
        }
       if(x<=n-1) return 0;
       return 1;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S,T;
        
        cin>>S>>T;

        Solution ob;
        cout << ob.checkCompressed(S,T) << endl;
    }
    return 0;
}
// } Driver Code Ends