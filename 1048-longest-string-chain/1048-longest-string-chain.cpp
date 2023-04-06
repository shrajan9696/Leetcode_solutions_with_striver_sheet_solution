class Solution {
public:
    static bool mycmp(string &s1,string &s2){
        return s1.size() < s2.size();
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),mycmp);
        int n = words.size();
        vector<int> lis(n);
        lis[0] = 1;
        for(int i=1;i<n;i++){
            lis[i] =1; 
            for(int j=0;j<i;j++){
                if((words[i].length() - words[j].length()) ==1){
                    int p1=0;
                    int p2=0;
                    while(p1<words[j].length() and p2<words[i].length()){
                        if(words[j][p1] == words[i][p2]){
                            p1++;
                            p2++;
                        }
                        else{
                            p2++;
                        }
                    }
                   
                     
                    if(p1 == words[j].length()) {
                        lis[i] = max(lis[i],lis[j]+1);
                    }
                }
            }
        }
        int res= INT_MIN;
        for(int i=0;i<n;i++){
            // cout<<lis[i]<<" ";
            res = max(res,lis[i]);
        } 
        return res;
    }
};