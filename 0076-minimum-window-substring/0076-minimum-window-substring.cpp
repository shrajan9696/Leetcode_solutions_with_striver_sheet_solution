class Solution {
public:
    string minWindow(string s, string t) {
     map<char,int> ms;
        map<char,int> mt;
        set<char> st;
        // for(int i=0;i<s.length();i++) ms[s[i]]++;
        for(int i=0;i<t.length();i++){
            mt[t[i]]++;
            st.insert(t[i]);
        }
        int req = t.length();
        int start=0;
        int end=0;
        int x=-1;
        int e=-1;
        int count=0;
        int ans=INT_MAX;
        while(start<s.length() and end<s.length()){
            ms[s[end]]++;
            if(st.find(s[end])!=st.end()){
                if(ms[s[end]]<=mt[s[end]]) count++;
            }
            while(count>=req){
                
              
                if(ans>(end-start+1)){
                      x=start;
                e = end;
                    ans = end-start+1;
                }
                // ans = min(ans,(end-start+1));
                ms[s[start]]--;
                if(st.find(s[start])!=st.end()){
                            if(ms[s[start]]<mt[s[start]]) count--;
                    
                        }
                start++;
            }
            end++;
        }
        if(x==-1 or e==-1) return "";
        else{
            string ans="";
            for(int i=x;i<=e;i++) ans+=s[i];
            return ans;
        }
    }
};