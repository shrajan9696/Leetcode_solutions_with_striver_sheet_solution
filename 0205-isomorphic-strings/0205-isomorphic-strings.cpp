class Solution {
public:
    bool isIsomorphic(string s, string t) {
     map<char,char> m;
       
        // for(int i=0;i<26;i++) m[char('a'+i)] = '0';
        set<char> st;
      for(int i=0;i<s.length();i++)
      {
          if(m.count(s[i])==0) {
            
              if(st.find(t[i])!=st.end()) return false;
                m[s[i]] = t[i];
             
          }
          
          else if(t[i]!=m[s[i]]) return false;
          cout<<m[s[i]]<<" ";
          st.insert(t[i]);
      }
        return true;
    }
};