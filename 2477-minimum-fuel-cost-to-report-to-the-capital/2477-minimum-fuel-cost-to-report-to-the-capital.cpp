class Solution {
public:
    long long ans=0;
    
    long long DFS(vector<int> adj[],vector<bool> &vis,int source,int seats){
        vis[source] = true;
        int count=1;
        for(auto x:adj[source]){
            if(vis[x]==false){
                count+=DFS(adj,vis,x,seats);
            }
        }
        
        // int noc = ceil(float(count)/seats);
        int noc = count/seats;
        if(count%seats!=0) noc++;
        if(source!=0) {
            ans+=noc;
        //     cout<<source<<" "<<count<<" "<<noc<<"\n";
        }
        // ans+=noc;
       
        return count;
        
    }
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size();
        n++;
        vector<int> adj[n];
        vector<bool> vis(n,false);
        for(int i=0;i<roads.size();i++)
        {
            adj[roads[i][0]].push_back(roads[i][1]);
            adj[roads[i][1]].push_back(roads[i][0]);
            
        }
       int x = DFS(adj,vis,0,seats);
         // cout<<"\n";
        return ans;
       
    }
};