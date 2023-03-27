class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> prices_min;
        vector<int> prices_max;
         prices_min.push_back(prices[0]);
         prices_max.push_back(prices[n-1]);
        for(int i=1;i<prices.size();i++){
            prices_min.push_back(min(prices_min.back(),prices[i]));
        }
         for(int i=n-2;i>=0;i--){
            prices_max.push_back(max(prices_max.back(),prices[i]));
        }
        reverse(prices_max.begin(),prices_max.end());
        int ans=0;
        for(int i=0;i<n;i++){
            ans = max(ans,prices_max[i]-prices_min[i]);
        }
        return ans;
    }
};