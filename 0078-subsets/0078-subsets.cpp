class Solution {
public:
      vector<vector<int>> ans;
    void generate(vector<int> nums,int index, vector<int> res,int n){
        if(index>=n){
            ans.push_back(res);
            return;
        }
        res.push_back(nums[index]);
        generate(nums,index+1,res,n);
        res.pop_back();
        generate(nums,index+1,res,n);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
         vector<int> res;
        int n = nums.size();
        generate(nums,0,res,n);
        return ans;
    }
};