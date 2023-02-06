class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
      int i=0;
        vector<int> p,neg;
        int n=nums.size();
        while(i<n)
        {
            if(nums[i]>=0) p.push_back(nums[i]);
            else neg.push_back(nums[i]);
            i++;
        }
        int x=0;
        int y=0;
        
        for(int i=0;i<n;i++)
        {
            if(i%2==0) {
                nums[i] = p[x];
                x++;
            }
            else{
                nums[i] = neg[y];
                y++;
            }
        }
        return nums;
    }
};