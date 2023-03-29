//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
vector<int> ans;
void generate(vector<int> arr,vector<int> res,int sum,int index,int n ){
    if(index>=n){
        ans.push_back(sum);
        return;
    }
    res.push_back(arr[index]);
    sum+=arr[index];
    generate(arr,res,sum,index+1,n);
    sum-=arr[index];
    res.pop_back();
     generate(arr,res,sum,index+1,n);
}
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        int index=0;
        vector<int> res;
        generate(arr,res,0,0,N);
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends