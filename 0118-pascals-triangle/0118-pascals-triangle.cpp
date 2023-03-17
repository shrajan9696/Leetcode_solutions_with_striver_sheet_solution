class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> v;
        vector<int> res;
        res.push_back(1);
        v.push_back(res);
        for(int i=1;i<numRows;i++){
            vector<int> res;
            res.push_back(1);
           
             for(int j=1;j<v[i-1].size();j++){
                 res.push_back(v[i-1][j-1] + v[i-1][j]);
             }
             res.push_back(1);
            v.push_back(res);
        }
        return v;
    }
};