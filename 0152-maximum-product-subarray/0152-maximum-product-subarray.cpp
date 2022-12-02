class Solution {
public:
    // ans is only possible from start or end;
   
    int maxProduct(vector<int>& nums) {
         int ans=INT_MIN;
    int n  = nums.size();
        int cpod=1;
        for(int i=0;i<nums.size();i++){
            cpod = cpod*nums[i];
            ans = max(ans,cpod);
            if(cpod == 0){
                cpod=1;
            }
            
        }
          cpod=1;
         for(int i=n-1;i>=0;i--){
            cpod = cpod*nums[i];
            ans = max(ans,cpod);
            if(cpod == 0){
                cpod=1;
            }
            
        }
         return ans;
    }
   
};