class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> adj[n];
        for(int i=0;i<times.size();i++){
            adj[times[i][0]-1].push_back({times[i][1]-1,times[i][2]});
            
        }
         priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,k-1});
        vector<int> dis(n,INT_MAX);
        dis[k-1] = 0;
        while(!pq.empty()){
            auto u = pq.top();
            int weight = u.first;
            int v = u.second;
            pq.pop();
            for(auto x:adj[v]){
                if(dis[x.first]>(weight+x.second)){
                    dis[x.first] = weight+x.second;
                     pq.push({dis[x.first],x.first});   
                }
            }
        }
        for(int i=0;i<dis.size();i++){
            if(dis[i] == INT_MAX) return -1;
        }
        return *max_element(dis.begin(),dis.end());
        
        
        
    }
};