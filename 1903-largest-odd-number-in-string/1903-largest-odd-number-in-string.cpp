class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.length(); 
        string res="";
        int point=-1;
        for(int i=n-1;i>=0;i--)
        {
            int x = num[i] - '0';
            if(x%2!=0){
                point=i;
                break;
            }
        }
        for(int i=0;i<=point;i++) res+=num[i];
        return res;
    }
};