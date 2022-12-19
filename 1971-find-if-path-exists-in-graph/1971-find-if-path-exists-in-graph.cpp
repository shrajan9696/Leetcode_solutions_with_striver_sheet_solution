class Solution {
public:
    
    void addEdge( vector<int> adj[],int u,int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void DFS(vector<int> adj[],int source,bool visited[])
    {
        visited[source]  = true;
        for(auto x:adj[source])
        {
            if(visited[x] == false){
                DFS(adj,x,visited);
            }
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        bool visited[n+1];
        vector<int> adj[n];
        for(int i=0;i<edges.size();i++)
        {
            addEdge(adj,edges[i][0],edges[i][1]);
        }
        for(int i=0;i<n;i++) visited[i] = false;
        DFS(adj,source,visited);
        if(visited[destination]) return true;
        return false;
    }
};