class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2!=0) nums[i] = 1;
            else nums[i] =0;
        }
        int sum=0;
        map<int,int> m;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(sum==k) ans++;
               ans+=m[sum-k] ;
            m[sum]++;
        }
        return ans;
    }
};