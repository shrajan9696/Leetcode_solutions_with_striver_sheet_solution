class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n = nums.size();
        int i=0;
        long long int count=0;
        long long int ans=0;
        for(int i=0;i<nums.size();){
            int flag=0;
        while(i<n and nums[i] == 0){
            flag=1;
            count++;
            i++;
        }
            ans+=((count*(count+1))/2);
            count=0;
            if(flag==0) i++;
        }
        return ans;
        
    }
};