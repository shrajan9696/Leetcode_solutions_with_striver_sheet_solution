class Solution {
public:
    bool halvesAreAlike(string s) {
         transform(s.begin(), s.end(), s.begin(), ::tolower);
          int n = s.length();
        int count1=0,count2=0;
        for(int i=0;i<(n/2);i++){
            if(s[i]=='a' or s[i]=='e' or s[i]=='o' or s[i]=='i' or s[i]=='u') count1++;
            if(s[(n/2)+i]=='a' or s[(n/2)+i]=='i' or s[(n/2)+i]=='e' or s[(n/2)+i]=='o' or s[(n/2)+i]=='u'  ) count2++;
        }
        if(count1==count2) return true;
        return false;
    }
};