class Solution {
public:
    
    // very similar to book allocation problem
    bool isValid(vector<int> piles,int ans,int h){
        long long int curr = 0;
        for(int i=0;i<piles.size();i++){
            curr+=(piles[i]/ans);
            if(piles[i]%ans!=0) curr++;
        }
        return (curr<=h);
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        long long int low=1;
        long long int high = *max_element(piles.begin(),piles.end());
        long long int res= high;
        while(low<=high){
            long long int mid = low + (high-low)/2;
            if(isValid(piles,mid,h)){
                res=mid;
                high = mid-1;
            }
            else low = mid+1;
        }
         return res;
    }
   
};