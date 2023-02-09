//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
bool check(vector<int> adj[],int source,vector<int>&color)
{
     queue<int> q;
	    q.push(source);
	    color[source] = 0;
	    while(!q.empty())
	    {
	        int u = q.front();
	        q.pop();
	        for(auto x:adj[u])
	        {
	            if(color[x]!=-1)
	            {
	               // if(color[x]!=(!color[u])) return false;
	               if(color[u] == color[x]) return false;
	            }
	            else
	            {
	                q.push(x);
	                if(color[u] == 1) color[x] = 0;
	                else color[x] = 1;
	            }
	        }
	    }
	    return true;
}
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    vector<int> color(V);
	    for(int i=0;i<V;i++) color[i] = -1;
	    for(int i=0;i<V;i++)
	    {
	        if(color[i] == -1){
	            if(!check(adj,i,color)) return false;
	        }
	    }
	    return true;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends