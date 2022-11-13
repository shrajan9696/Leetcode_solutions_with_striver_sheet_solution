class Solution {
public:
    int subarrayLCM(vector<int>& nums, int k) {
        long long int count=0;
        for(int i=0;i<nums.size();i++){
            int ans = nums[i];
            for(int j=i;j<nums.size();j++)
            {
               
               
              
                  ans = ((nums[j] * ans)) /
                (__gcd( (nums[j]), ans));
                         
                if(ans==k) count++;
                else if(ans>k) break;
            }
            
        }
        return count;
    }
};