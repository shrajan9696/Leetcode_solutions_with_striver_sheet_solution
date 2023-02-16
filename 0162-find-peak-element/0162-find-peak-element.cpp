class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int i=0;
        int j= nums.size()-1;
        int n = nums.size();
        while(i<=j){
            int mid = (i+j)/2;
            if(((mid==0)||(nums[mid-1]<nums[mid])) && ((mid==n-1) || (nums[mid+1]<nums[mid]))) {
                return mid;
            }
            else if( mid>0 and nums[mid-1]>nums[mid] ) j = mid-1;
            else i = mid+1;
        }
        return 0;
    }
};