class Solution {
public:
    string pushDominoes(string dominoes) {
        string s;
        s+='L';
        for(int i=0;i<dominoes.length();i++)
        {
            s+=(dominoes[i]);
        }
        s+='R';
        int low=0;
        int high=1;
        while(high<s.length()){
            if(s[high]=='.'){
                high++;
            }
            else{
                if(s[low]=='L' and s[high]=='L'){
                    for(int i=low+1;i<high;i++){
                        s[i]='L';
                    }
                }
                 else if(s[low]=='R' and s[high]=='R'){
                    for(int i=low+1;i<high;i++){
                        s[i]='R';
                    }
                }
                else if(s[low]=='R' and s[high]=='L'){
                    int rem = (high-low-1);
                    if(rem%2==0){
                        for(int i=low+1;i<=(low+rem/2);i++){
                            s[i]='R';
                        }
                         for(int i=(low+ rem/2)+1;i<=(high);i++){
                            s[i]='L';
                        }
                    }
                    else{
                        for(int i=low+1;i<=(low+rem/2);i++){
                            s[i]='R';
                        }
                        for(int i=(low+ rem/2 + 2);i<high;i++){
                            s[i]='L';
                        }
                    }
                   
                }
                low=high;
                high++;
               
            }
        }
        string ans="";
        for(int i=1;i<s.length()-1;i++) ans+=s[i];
        return ans;
    }
};