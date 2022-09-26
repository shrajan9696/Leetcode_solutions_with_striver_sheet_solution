class Solution {
public:
    bool isPalindrome(int x) {
        int temp=x;
        long long int rev=0;
        if(x>=0){
        while(temp!=0){
            int ld=temp%10;
            rev = rev*10+ld;
            temp=temp/10;
        }
        return(rev==x);
        }
        else
            return false;
    }
};