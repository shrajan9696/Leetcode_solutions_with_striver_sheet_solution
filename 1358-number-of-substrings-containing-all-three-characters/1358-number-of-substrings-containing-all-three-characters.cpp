class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> a;
        vector<int> b;
        vector<int> c;
        int n = s.length();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='a') a.push_back(i);
            else if(s[i]=='b') b.push_back(i);
            else c.push_back(i);
        }
        int i=0;
        int j=0;
        int k=0;
        while(i<a.size() and j<b.size() and k<c.size()){
            int mn = min(a[i],min(b[j],c[k]));
            int mx = max(a[i],max(b[j],c[k]));
            ans+=(n-mx);
            if(mn == a[i]) i++;
            else if(mn == b[j]) j++;
            else if(mn == c[k]) k++;
        }
        return ans;
    }
};