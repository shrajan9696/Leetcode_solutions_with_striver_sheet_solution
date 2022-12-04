class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        

        // Your code here
        set<int> st;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]>0) st.insert(nums[i]);
        }
        int j=1;;
        for(auto x:st){
            if(x!=j) return j;
            j++;
        }
        return j;
    
    }
};