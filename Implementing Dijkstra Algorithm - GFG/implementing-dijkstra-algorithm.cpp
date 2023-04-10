//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
       vector<int> dist(V,INT_MAX);
       vector<bool> finalised(V,false);
       dist[S]=0;
    //   priority_queue<pair<int,int>> pq;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> >pq;
      pq.push({0,S});
      while(!pq.empty()){
          auto p = pq.top();
          pq.pop();
          int v = p.second;
          int weight  = p.first;
          finalised[v] = true;
          vector<vector<int>> graph = adj[v];
          
          for(int i=0;i<graph.size();i++)
          {
              if(finalised[graph[i][0]] == false){
                //   dist[graph[i][0]] = min(dist[graph[i][0]], weight+graph[i][1]);
                if(dist[graph[i][0]] > weight+graph[i][1]){
                        dist[graph[i][0]] = weight+graph[i][1];
                  pq.push({dist[graph[i][0]],graph[i][0]});
                }
              }
          }
      }
    
      
    
       return dist;
    }  
        
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends