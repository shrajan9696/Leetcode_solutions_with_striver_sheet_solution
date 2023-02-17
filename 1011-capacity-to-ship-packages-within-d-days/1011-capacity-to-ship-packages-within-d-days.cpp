class Solution {
public:
    bool isCapable(vector<int> nums,int ans,int days){
        long long int sum=0;
        int curr = 1;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]>ans) return false;
            if(sum+nums[i]>ans){
                sum = nums[i];
                curr = curr+(nums[i]/ans);
                if(nums[i]%ans!=0) curr++;
                // curr++;
            }
            else sum+=nums[i];
        }
        return curr<=days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        long long int sum=0;
        for(int i=0;i<weights.size();i++) sum+=weights[i];
        long long int low = 1;
        long long int high = sum;
        int res = sum;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(isCapable(weights,mid,days)){
             res=mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        return res;
    }
};