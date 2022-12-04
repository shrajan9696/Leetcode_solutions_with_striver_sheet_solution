class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        

        // Your code here
        unordered_map<int,int> m;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]>0) m[nums[i]]++;
        }
        int j=1;;
        for(int i=0;i<m.size();i++)
        {
            if(m[j]<=0) return j;
            j++;
        }
        return j;
    }
};