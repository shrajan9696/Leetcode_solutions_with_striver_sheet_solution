class Solution {
public:
    
    void BFS(vector<vector<int>> v,int s,bool visited[]){
        queue<int> q;
        q.push(s);
        while(q.empty()==false)
        {
             int temp=q.front();
            q.pop();
            visited[temp] = true;
            for(auto y:v[temp])
            {
                   if(visited[y]==false)
                   {
                       q.push(y);
                       visited[y]=true;
                   }      
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> v(n+1);
        for(int i=0;i<isConnected.size();i++)
        {
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1 and i!=j){
                    v[i].push_back(j);
                }
            }
        }
        int count=0;
        bool visited[n];
        for(int i=0;i<n;i++) visited[i] = false;
        for(int i=0;i<n;i++){
             if(visited[i]==false){
                 
                 BFS(v,i,visited);
                 // for(auto x:visited) cout<<x<<" ";
                 // cout<<"\n";
                 count++;
             }
        }
        return count;
    }
};