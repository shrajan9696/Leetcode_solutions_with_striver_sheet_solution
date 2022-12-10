//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
string buildLowestNumber(string num, int k);
// Driver program to test above function
int main()
{
    int t,n;
    string str;
    cin>>t;
    while(t--)
    {
    cin>>n;
    cin>>str;
    cout << buildLowestNumber(str, n)<<endl;
    }
    return 0;
}

// } Driver Code Ends


string buildLowestNumber(string num, int k)
{
    //code here.
    stack<char> st;
    for(int i=0;i<num.length();i++)
    {
        while(!st.empty() and st.top()>num[i] and k>0)
        {
            st.pop();
            k--;
        }
        st.push(num[i]);
    }
     while(!st.empty() and k>0)
        {
            st.pop();
            k--;
        }
        string res="";
        while(!st.empty())
        {
            res+=st.top();
            st.pop();
        }
        for(int i=res.length()-1;i>0;i--)
        {
        if(res[i]=='0') res.pop_back();
        else break;
        }
        reverse(res.begin(),res.end());
        
        return res ;
}