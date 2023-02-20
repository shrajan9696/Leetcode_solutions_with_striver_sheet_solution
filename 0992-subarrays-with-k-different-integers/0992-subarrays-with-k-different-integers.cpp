class Solution {
public:
    int count(vector<int> nums,int k){
        map<int,int> m;
        int start=0;
        int end=0;
        int ans=0;
        while(start<nums.size() and end<nums.size()){
            m[nums[end]]++;
            while(m.size()>k){
                m[nums[start]]--;
                if(m[nums[start]]==0) {
                    m.erase(nums[start]);
                }
                start++;
            }
            if(m.size()<=k){
                ans+=(end-start+1);
            }
            end++;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return (count(nums,k) - count(nums,k-1));
    }
};