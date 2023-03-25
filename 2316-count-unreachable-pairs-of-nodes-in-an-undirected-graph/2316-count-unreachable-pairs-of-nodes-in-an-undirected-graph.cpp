class Solution {
public:
    void DFS(vector<int> adj[],vector<bool>&visited,int &count,int source){
     visited[source] =  true;
        for(auto x:adj[source]){
            if(visited[x] == false){
                count++;
                 DFS(adj,visited,count,x);
            }
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<bool> visited(n,false);
        vector<int> res;
        for(int i=0;i<n;i++){
            if(visited[i] == false){
                int count = 1;
                DFS(adj,visited,count,i);
                res.push_back(count);
            }
        }
        // for(auto x:res) cout<<x<<" ";
        // cout<<"\n";
        
         long long ans = 0;
    long long sum = 0;
    long long Mod = 1000000007;
    for (int i = 0; i <res.size() ; i++) {
        ans += (sum * res[i]) ;
        // ans %= Mod;
        sum += res[i];
        // sum %= Mod;
    }
    return ans;
    }
};