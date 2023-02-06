class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        // using lomuto partition
       int e=0;
        int o=1;
        int n = nums.size();
        while(e<n and o<n)
        {
            while(e<n and nums[e]%2==0) e=e+2;
            while(o<n and nums[o]%2==1) o = o+2;
            if(e<n and o<n)swap(nums[e],nums[o]);
        }
        return nums;
    }
};