class Solution {
public:
    int countOdds(int low, int high) {
        int count = high-low+1;
        if(count%2==0) return count/2;
            else{
                if(low%2==0) return count/2;
                    else return count/2+1;
            }
    }
};