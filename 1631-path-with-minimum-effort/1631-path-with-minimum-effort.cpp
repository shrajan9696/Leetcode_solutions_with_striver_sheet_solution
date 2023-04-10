class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> distance(n,vector<int>(m,INT_MAX));
        distance[0][0] = 0;
         priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> pq;
        pq.push({0,{0,0}});
        while(!pq.empty()){
            int weight = pq.top().first;
            int row = pq.top().second.first;
            int col =  pq.top().second.second;
            pq.pop();
            int delrow[4] = {-1,0,1,0};
            int delcol[4] = {0,1,0,-1};
            for(int i=0;i<4;i++){
                int nrow = row+delrow[i];
                int ncol = col+delcol[i];
                if(nrow>=0 and nrow<n and ncol>=0 and ncol<m){
                  
                         
                        int price = (max(abs(heights[nrow][ncol] - heights[row][col]),weight));
                    if(price<distance[nrow][ncol]){
                        distance[nrow][ncol] = price;
                         pq.push({distance[nrow][ncol],{nrow,ncol}});
                    }
                         // distance[nrow][ncol] = max(distance[row][col],(max(abs(heights[nrow][ncol] - heights[row][col]),(weight))));
                       
                        
                   
                    
            }
        }
        }
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         cout<<distance[i][j]<<" ";
        //     }
        //     cout<<"\n";
        // }
        // cout<<"\n";
        return distance[n-1][m-1];
    }
};