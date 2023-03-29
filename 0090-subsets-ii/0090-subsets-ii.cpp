class Solution {
public:
    set<vector<int>> s;
    void generate(vector<int> nums,vector<int> res,int index,int n){
        if(index>=n){
            s.insert(res);
            return;
        }
        res.push_back(nums[index]);
        generate(nums,res,index+1,n);
        res.pop_back();
        generate(nums,res,index+1,n);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
       sort(nums.begin(),nums.end());
        vector<int> res;
        generate(nums,res,0,nums.size());
        vector<vector<int>> ans;
        for(auto x:s){
            ans.push_back(x);
        }
        return ans;
    }
};