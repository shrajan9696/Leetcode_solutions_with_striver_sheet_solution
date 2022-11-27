//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	string addBinary(string A, string B)
	{
	    // your code here
	    char c = '0';
	   int n = A.length();
	   int m = B.length();
	   string res="";
	   int i=n-1;
	   int j=m-1;
	   while(i>=0 and j>=0)
	   {
	       if(A[i]=='0' and B[j]=='0')
	       {
	           res+=c;
	           c='0';
	           
	       }
	       else if(A[i]=='1' and B[j]=='1')
	       {
	           res+=c;
	           c='1';
	       }
	       else{
	           if(c=='1'){
	               res+='0';
	           }
	           else{
	               res+='1';
	           }
	       }
	       i--;
	       j--;
	      
	   }
	   while(i>=0)
	   {
	       if(c=='1'){
	           if(A[i]=='0'){
	               res+='1';
	               c='0';
	           }
	           else if(A[i]=='1'){
	               res+='0';
	               c='1';
	           }
	       }
	       else
	       {
	           res+=A[i];
	       }
	       i--;
	   }
	   
	    while(j>=0)
	   {
	       if(c=='1'){
	           if(B[j]=='0'){
	               res+='1';
	               c='0';
	           }
	           else if(B[j]=='1'){
	               res+='0';
	               c='1';
	           }
	       }
	       else
	       {
	           res+=B[j];
	       }
	       j--;
	   }
	   
	   if(c=='1') res+=c;
	    while(res.back()!='1')
	   {
	       res.pop_back();
	   }
	   reverse(res.begin(),res.end());
	  
	   
	   return res;
	   
	}
};

//{ Driver Code Starts.

int main()
{
	int t; cin >> t;
	while (t--)
	{
		string A, B; cin >> A >> B;
		Solution ob;
		cout << ob.addBinary (A, B);
		cout << "\n";
	}
}

// Contributed By: Pranay Bansal

// } Driver Code Ends