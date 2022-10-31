class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
   
        vector<string> answer;
        for(int i=0;i<queries.size();i++){  
            int flag=0;
            for(int j=0;j<dictionary.size();j++){
                if(flag==1) break;
                if(queries[i].length()==dictionary[j].length()){
                    int count=0;
                    for(int k=0;k<queries[i].length();k++){
                        if(queries[i][k] != dictionary[j][k]) count++;
                    }
                    if(count<=2)  {
                        answer.push_back(queries[i]);
                        flag = 1;
                    }
                }
            }
        }
       
        return answer;
    }
};