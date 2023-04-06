class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // O(n*n) solution
        
//         int n = nums.size();
//         vector<int> dp(n,0);
//         dp[0] = 1;
//         for(int i=1;i<n;i++){
            
         
       
//                 dp[i] = 1;
//                 for(int j=0;j<i;j++){
//                     if(nums[j]<nums[i]) dp[i] = max(dp[i],dp[j]+1);
//                 }
            
//         }
//         return *max_element(dp.begin(),dp.end());
        
        int n = nums.size();
          vector<int> dp;
        dp.push_back(nums[0]);
        for(int i=1;i<n;i++){
            if(nums[i]>dp.back()) dp.push_back(nums[i]);
           
            else{
                 auto it = lower_bound(dp.begin(),dp.end(),nums[i]);
                   dp[it-dp.begin()] = nums[i];
              
            }
        //      for(auto x:dp) cout<<x<<" ";
        // cout<<"\n";
        }
       
        return dp.size();
        
        
    }
};