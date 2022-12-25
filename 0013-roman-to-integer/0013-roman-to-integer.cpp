class Solution {
public:
    int romanToInt(string s) {
     map<char,int> m;
        m['I'] =1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;
        int num=0;
        stack<char> st;
        int ans=0;
        int i=0;
        for( i=0;i<s.length()-1;)
        {
            char ch = s[i+1];
            if(ch == 'V' and s[i]=='I') {
                ans+=4;
                i=i+2;
            }
            else  if(ch == 'X' and s[i]=='I') {
                ans+=9;
                i=i+2;
            }
             else  if(ch == 'L' and s[i]=='X') {
                ans+=40;
                i=i+2;
            }
             else  if(ch == 'C' and s[i]=='X') {
                ans+=90;
                i=i+2;
            }
             else  if(ch == 'D' and s[i]=='C') {
                ans+=400;
                i=i+2;
            }
             else  if(ch == 'M' and s[i]=='C') {
                ans+=900;
                i=i+2;
            }
            else {
               
                ans+=m[s[i]];
                i++;
            }
        }
        if(i==s.length()-1) ans+=m[s[i]];
        return ans;
    }
};