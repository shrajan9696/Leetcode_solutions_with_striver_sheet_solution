class Solution {
public:
    int beautySum(string s) {
       
        int ans=0;
       
        for(int i=0;i<s.length();i++){
          
        int mx = 0;
          
            map<char,int> m;
            for(int j=i;j<s.length();j++)
            {
                   int mn = INT_MAX;
                m[s[j]]++;
                mx = max(mx,m[s[j]]);
               
              
               
               for(auto i : m) mn = min(mn, i.second);
           
                // cout<<mx<<" "<<mn<<"\n";
    
                ans+=(mx-mn);
                // cout<<ans<<" ";
            }
        }
        return ans;
    }
};