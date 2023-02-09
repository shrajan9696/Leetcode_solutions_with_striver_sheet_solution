//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int longestUniqueSubsttr(string S){
        //code
    //     unordered_map<char,int> m;
    //     int start = 0;
    //     int end = 0;
    //     int ans=1;
    //   while(start<S.length() and end<S.length())
    //     {
    //         m[S[end]]++;
    //         if(m.size() == (end-start+1)) ans = max(ans,(end-start+1));
    //         else
    //         {
    //             while(m.size()<(end-start+1)){
    //                 m[S[start]]--;
    //                 if(m[S[start]] == 0) m.erase(S[start]);
    //                 start++;
    //             }
    //         }
    //         end++;
    //     }
    //     return ans;
    //  int start=0;
    //     int e=0;
    //     int ans=0;
    //     unordered_set<char> st;
    //     while(start<S.length() and e<S.length())
    //     {
    //         auto it = st.find(S[e]);
    //         if(it==st.end()){
    //             ans=max(ans,(e-start+1));
    //             st.insert(S[e]);
    //             e++;
    //         }
    //         else{
    //             st.erase(S[start]);
    //             start++;
    //         }
    //     }
    //     return ans;
    
    int arr[26]={0};
    int s=0;
    int e=0;
    int n = S.length();
    int ans=0;
    while(s<n and e<n)
    {
        arr[S[e]-'a']++;
        while(arr[S[e]-'a']>1)
        {
            arr[S[s]-'a']--;
            s++;
        }
           ans = max(ans,(e-s+1));
            e++;
        
    }
      return ans;  
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string str;
		cin>>str;
		Solution ob;
		cout<<ob.longestUniqueSubsttr(str)<<endl;
	}
	return 0;
}
// } Driver Code Ends