class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) {
        int count=0;
        for(int i=0;i<nums.size();i++){
            int g = nums[i];
            if(g==k) count++;
            for(int j=i+1;j<nums.size();j++){
                
                g = __gcd(g,nums[j]);
                if(g==k) count++;
            }
            
        }
        return count;
    }
};