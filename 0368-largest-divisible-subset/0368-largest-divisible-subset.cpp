class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        int ans = 1;
        sort(nums.begin(),nums.end());
        vector<int> lis(n);
        lis[0] = 1;
        for(int i=1;i<n;i++){
            lis[i] = 1;
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j] == 0){
                    lis[i] = max(lis[i],lis[j]+1);
                    ans = max(ans,lis[i]);
                }
            }
        }
     
        int pos = max_element(lis.begin(),lis.end()) - lis.begin();
        int x = nums[pos];
        vector<int> res;
        res.push_back(nums[pos]);
        ans--;
        int i = pos-1;
      
        // for(auto x:lis) cout<<x<<" ";
        while(i>=0 and ans>0){
            if(x%nums[i] == 0 and (lis[pos] - lis[i]) == 1){
                pos = i;
               res.push_back(nums[i]);
                x = nums[i];
                ans--;
            }
            i--;
        }
        reverse(res.begin(),res.end());
        // cout<<"\n";
        return res;
        
    }
};