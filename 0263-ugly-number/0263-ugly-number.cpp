class Solution {
public:
    bool isUgly(int n) {
        if(n<=0) return false;
        for( int i=2;i*1LL*i<=n;i++){
            while(n%i==0){
                if(i==2 or i==3 or i==5){
                    n = n/i;
                }
                else return false;
            }
           
        }
         if(n>1){
              if(n==2 or n==3 or n==5) return true;
             else return false;
            }
        return true;
    }
};