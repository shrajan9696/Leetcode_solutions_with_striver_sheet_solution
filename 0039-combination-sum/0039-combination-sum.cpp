class Solution {
public:
    vector<vector<int>> ans;
    void function(vector<int>arr,int target,int index,vector<int> res,int n){
        if(  target<=0 or index>=n){
            if(target==0)ans.push_back(res);
            return;
            
        }
        res.push_back(arr[index]);
        target-=arr[index];
         function(arr,target,index,res,n);
        target+=arr[index];
        res.pop_back();
        function(arr,target,index+1,res,n);
        
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> res;
        function(candidates,target,0,res,candidates.size());
        return ans;
        
    }
};