class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) 
    {
        map<int,int> winner;
        map<int,int> looser;
        for(int i=0;i<matches.size();i++)
        {
            winner[matches[i][0]]++;
            looser[matches[i][1]]++;
        }
        vector<vector<int>> ans;
        vector<int> v;
        for(pair<int,int>p:winner)
        {
            if(p.second > 0)
            {
                v.push_back(p.first);
            }
        }
        vector<int> res;
        for(int i=0;i<v.size();i++)
        {
            if(looser[v[i]]==0){
              res.push_back(v[i]);  
            }
        }
        ans.push_back(res);
        v.clear();
         for(pair<int,int>p:looser)
        {
            if(p.second == 1)
            {
                v.push_back(p.first);
            }
        }
       
           ans.push_back(v);
        return ans;
    }
};