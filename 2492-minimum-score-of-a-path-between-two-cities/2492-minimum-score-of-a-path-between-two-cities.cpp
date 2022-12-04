class Solution {
public:
    int ans=INT_MAX;
   
        void DFS(vector<vector<pair<int,int>>>&v,int s,vector<bool>&visited)
        {
            if(visited[s]==true) return;
            visited[s] = true;
           
            for(auto x:v[s])
            {
                 ans = min(ans,x.second);
                if(visited[x.first] == false){
                    // visited[x.first] = true;
                    
                    DFS(v,x.first,visited);
                }
            }
        }
    
    int minScore(int n, vector<vector<int>>& roads) 
    {
        
       
        vector<vector<pair<int,int>>> v(n+1);
        for(int i=0;i<roads.size();i++)
        {
            v[roads[i][0]].push_back({roads[i][1],roads[i][2]});
              v[roads[i][1]].push_back({roads[i][0],roads[i][2]});
        }
        // for(auto x:v){
        //     for(auto y:x){
        //         cout<<y.first<<" "<<y.second<<" ";
        //     }
        //     cout<<"\n";
        // }
       
       
       vector<bool> visited(n+1,false);
//       for(int i=0;i<n+1;i++){
//           visited[i] = false;
//       }
        
        int source=1;
        DFS(v,source,visited);
        return ans;
    }
};