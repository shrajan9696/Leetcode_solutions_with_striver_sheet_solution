class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int v = graph.size();
        vector<int> adj[v];
        for(int i=0;i<v;i++){
            for(int j=0;j<graph[i].size();j++){
                adj[graph[i][j]].push_back(i);
            }
        }
        vector<int> indegree(v,0);
        queue<int> q;
           for(int i=0;i<v;i++){
            for(auto x:adj[i]){
                indegree[x]++;
            }
        }
         for(int i=0;i<v;i++){
            if(indegree[i]==0) q.push(i);
        }
        int count=0;
        vector<int> ans;
        while(!q.empty()){
            int u = q.front();
            ans.push_back(u);
            q.pop();
            for(auto x:adj[u]) {
                indegree[x]--;
                if(indegree[x] == 0) q.push(x);
            }
            count++;
        }
        // cout<<count;
        // return (count==n);
        sort(ans.begin(),ans.end());
      return ans;
    }
};