class Solution {
public:
    bool overlap(int cs,int ce,int ps,int pe)
    {
        if(cs>=ps)
        {
           if(cs>=ps and cs<=pe) return true;
            else return false;
        }
        else if(cs<ps)
        {
           if(ps>=cs and ps<=ce) return true;
            else return false;
        }
        return false;
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end());
        int start = intervals[0][0];
        int end= intervals[0][1];
        for(int i=1;i<intervals.size();i++)
        {
            if(overlap(intervals[i][0],intervals[i][1],start,end)){
                start = min(intervals[i][0],start);
                end = max(intervals[i][1],end);
            }
            else
            {
                ans.push_back({start,end});
                  start = intervals[i][0];
                  end= intervals[i][1]; 
            }
        }
         ans.push_back({start,end});
        return ans;
    
    }
};