class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
         int n = nums.size();
        int i=-1;
        int l=0;
        int h = n-1;
        int j=0;
        while(j<n){
            if(nums[j]%2==0)
            {
                i++;
                swap(nums[i],nums[j]);
            }
            j++;
        }
        // swap(nums[i],nums[h]);
        return nums;
    }
};