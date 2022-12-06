class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      
        int start=0;
        int e=0;
        int ans=0;
        set<char> st;
        while(start<s.length() and e<s.length())
        {
            auto it = st.find(s[e]);
            if(it==st.end()){
                ans=max(ans,(e-start+1));
                st.insert(s[e]);
                e++;
            }
            else{
                st.erase(s[start]);
                start++;
            }
        }
        return ans;
    }
};