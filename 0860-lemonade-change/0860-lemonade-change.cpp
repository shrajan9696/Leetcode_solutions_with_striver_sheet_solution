class Solution {
public:
    map<int,int> m;
    bool lemonadeChange(vector<int>& bills) {
     for(int i=0;i<bills.size();i++){
         if(bills[i]==5) {
             m[5]++;
         }
         else if(bills[i]==10){
             if(m[5]<=0) return false;
             else{
                 m[10]++;
                 m[5]--;
             }
         }
         else{
             if(m[10]>=1 and m[5]>=1){
                 m[20]++;
                 m[10]--;
                 m[5]--;
               
             }
             else if(m[5]>=3){
                   m[20]++;
                 // m[10]--;
                 m[5]--;
                  m[5]--;
                  m[5]--;
               
             }
             else return false;
             
         }
     }
        return true;
    }
};