//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        // Code here.
        map<int,int> m;
        
        int n = nums.size();
        if(n%2!=0) return false;
        for(int i=0;i<n;i++)
        {
            nums[i] = nums[i]%k;
            m[nums[i]]++;
        }
        for(int i=0;i<n;i++)
        {
            if(nums[i] == 0 and m[nums[i]]%2==0) continue;
            else if(nums[i] == 0 and m[nums[i]]%2!=0) return false;
                
            
            else{
            if(m[nums[i]]>0 and m[k-nums[i]]>0) 
            {
               if(nums[i] == (k-nums[i])) {
                   if(m[nums[i]]>=2){
                       m[nums[i]]--;
                       m[k-nums[i]]--;
                   }
                   else return false;
               }
               else{
                   m[nums[i]]--;
                       m[k-nums[i]]--;
               }
            }
            else if(m[nums[i]]<=0) continue;
            else return false;
        }
        }
        return true;
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}
// } Driver Code Ends