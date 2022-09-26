class Solution {
public:
    int majorityElement(vector<int>& nums) 
    {
      int count=1;
        int res=0;
        int n= nums.size();
        for(int i=1;i<n;i++)
        {
            if(nums[res] == nums[i]) count++;
            else count--;
            if(count==0)
            {
                count=1;
                res=i;
            }
        }
        
        
        return nums[res];
    }
};
