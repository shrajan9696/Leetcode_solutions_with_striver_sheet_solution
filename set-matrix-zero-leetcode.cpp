class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
       vector<int> r;
        vector<int> c;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                
                if(matrix[i][j]==0)
                {
                   r.push_back(i); 
                    c.push_back(j);
                }
                
            }
        }
        for(auto x:r) cout<<x<<" ";
        for(auto x:c) cout<<x<<" ";
         for(int k=0;k<r.size();k++)
         {
            for(int j=0;j<matrix[r[k]].size();j++){
                matrix[r[k]][j]=0;
            }
        }
                      
        
         for(int k=0;k<c.size();k++)
         {
            for(int j=0;j<matrix.size();j++){
                matrix[j][c[k]]=0;
            }
        }
       
    }
};
