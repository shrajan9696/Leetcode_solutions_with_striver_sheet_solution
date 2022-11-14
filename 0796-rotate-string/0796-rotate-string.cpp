class Solution {
public:
    bool rotateString(string s1, string s2) {
       for(int i=0;i<s1.length();i++)
        {
            char x = s1[0];
            for(int j = 1;j<s1.length();j++)
            {
                s1[j-1] = s1[j];
            }
            s1[s1.length()-1] = x;
            if(s1 == s2) return true;
            
        }
        return false;   
    }
};