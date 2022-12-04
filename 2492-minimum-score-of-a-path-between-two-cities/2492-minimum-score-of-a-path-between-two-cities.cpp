class Solution {
public:
      void dfs(int src,vector<pair<int,int>> g[],int &mn,vector<int> &vis){
        
        vis[src]=1;
        
        for(auto i:g[src]){
            
            int child=i.first;
            int wt=i.second;
            
            mn=min(mn,wt);
            
            if(!vis[child]){
                dfs(child,g,mn,vis);
            }
        }
        
    }
    int minScore(int n, vector<vector<int>>& roads) {
     vector<pair<int,int>> g[n+1];
        
        for(auto i:roads){
            
            int u=i[0];
            int v=i[1];
            int wt=i[2];
            
            g[u].push_back({v,wt});
            g[v].push_back({u,wt});
        }
        vector<int> vis(n+1,0);
        
        int mn=1e6;
        
        dfs(1,g,mn,vis);
        
        return mn;
        
    
    }
};