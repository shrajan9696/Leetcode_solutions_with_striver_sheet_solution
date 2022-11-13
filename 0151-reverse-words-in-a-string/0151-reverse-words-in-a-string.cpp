class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        for(int i=0;i<s.length();i++)
        {
            while(s[i]==' ') i++;
            int flag=0;
                string res="";
                for(int j=i;j<s.length();j++){
                    flag=1;
                    if(s[j]==' ') break;
                    res+=s[i];
                    i++;
                    
                }
               if(flag==1) st.push(res);
            
        }
        string ans= "";
        while(st.empty() == false)
        {
            ans+=st.top();
            ans+=' ';
            st.pop();
        }
        ans.pop_back();
        return ans;
    }
};