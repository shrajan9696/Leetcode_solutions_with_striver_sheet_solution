class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(),nums.end());
        int res=0;
       for(auto x:s)
       {
           int curr=1;
           if(s.find(x-curr)==s.end())
           {
               while(s.find(x+curr)!=s.end()) curr++;
               res=max(res,curr);
           }
       }
        return res;
    }
};