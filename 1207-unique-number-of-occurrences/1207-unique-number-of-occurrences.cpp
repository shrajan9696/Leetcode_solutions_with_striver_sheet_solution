class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) 
    {
        map<int,int>m;
        for(auto x:arr) m[x]++;
        vector<int> v;
        for(auto p:m){
            v.push_back(p.second);
        }
        sort(v.begin(),v.end());
        for(int i=1;i<v.size();i++){
            if(v[i]==v[i-1]) return false;
        }
        return true;
        
    }
};