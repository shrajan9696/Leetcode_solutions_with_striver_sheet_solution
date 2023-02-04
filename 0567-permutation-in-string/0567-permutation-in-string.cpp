class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        sort(s1.begin(),s1.end());
        if(s2.length()<s1.length()) return false;
        for(int i=0;i<=s2.length() - s1.length();i++)
        {
            string res="";
            for(int j=0;j<s1.length();j++)
            {
                res+=s2[i+j];
            }
            sort(res.begin(),res.end());
            if(res==s1) return true;
        }
        return false;
    }
};