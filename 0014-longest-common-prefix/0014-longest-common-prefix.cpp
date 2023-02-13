class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res="";
      
        
        for(int p=0;p<200;p++)
        {
              char x;
            if(p<strs[0].length()) x = strs[0][p];
            else break;
        int flag=0;
        for(int i=0;i<strs.size();i++)
        {
          
            if(p<strs[i].length())
            {
                if(strs[i][p] != x) 
                {
                    flag=1;
                    break; 
                }
            }
            else{
                flag=1;
                break;
            }
           
            
        }
            if(flag==1) break;
            res+=x;
            }
        return res;
    }
};