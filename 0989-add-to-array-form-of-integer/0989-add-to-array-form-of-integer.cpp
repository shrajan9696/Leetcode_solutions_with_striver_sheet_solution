class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
       // long long int ans=0;
       //  long long int x=1;
       //  for(int i=num.size()-1;i>=0;i--)
       //  {
       //      ans= ans+(x*num[i]);
       //      x=x*10;
       //  }
       //  ans = ans+k;
       //  vector<int> v;
       //  cout<<ans<<" ";
       //  while(ans>0)
       //  {
       //      v.push_back(ans%10);
       //      ans=ans/10;
       //  }
       // reverse(v.begin(),v.end());
       //  return v;
    //     string res="";
    //     for(int i=0;i<num.size();i++)
    //     {
    //        res+=(char(num[i]+'0'));
    //     }
    //     string s="";
    //    while(k>0)
    //     {
    //        int ld = k%10;
    //         k = k/10;
    //        s+=(char(ld+'0'));
    //     }
    //     reverse(s.begin(),s.end());
    //     int i = res.length()-1;
    //     int j = s.length()-1;
    //     string ans="";
    //     int c=0;
    //     while(i>=0 and j>=0){
    //         int n1 = int(num[i] - '0');
    //         int n2 = int(s[j]-'0');
    //         int number = n1+n2+c;
    //         int x = number%10;
    //         c = number/10;
    //         ans+=(char(x+'0'));
    //         j--;
    //         i--;
    //     }
    //     while(j>=0) {
    //         ans+=char(s[j]+'0');
    //         j--;
    //     }
    //     while(i>=0) {
    //         ans+=char(res[i]+'0');
    //             i--;
    //     }
    //     reverse(ans.begin(),ans.end());
        vector<int> v;
    //     for(int i=0;i<ans.length();i++)
    //     {
    //         v.push_back(int(ans[i]-'0'));
    //     }
    //     return v;
        
        int j  = num.size()-1;
        int c=0;
        while(j>=0 and k>0)
        {
            int n = num[j]+(k%10)+c;
            if(n==10) {
                c=1;
            }
                else c = n/10;
              v.push_back(n%10);
            j--;
            k = k/10;
        }
        
        while(k>0)
        {
             // v.push_back(k%10+c);
             // k = k/10;
             int n = (k%10)+c;
             k = k/10;
            if(n==10) {
                c=1;
            }
            else c = n/10;
            v.push_back(n%10);
        }
        while(j>=0){
            // v.push_back(num[j]+c);
            // j--;
            int n = num[j]+c;
            c = n/10;
            v.push_back(n%10);
            j--;
        }
        if(c==1) v.push_back(c);
        reverse(v.begin(),v.end());
        return v;
    }
};