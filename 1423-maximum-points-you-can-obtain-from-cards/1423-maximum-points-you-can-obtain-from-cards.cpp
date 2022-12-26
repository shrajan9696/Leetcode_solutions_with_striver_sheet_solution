class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        vector<int> prefix;
        vector<int> suffix;
        prefix.push_back(cardPoints[0]);
        for(int i=1;i<n;i++)
        {
            prefix.push_back(prefix.back()+cardPoints[i]);
        }
        suffix.push_back(cardPoints[n-1]);
        for(int i=n-2;i>=0;i--)
        {
            suffix.push_back(suffix.back()+cardPoints[i]);
        }
        reverse(suffix.begin(),suffix.end());
        int ans=INT_MIN;
        int i=0;
        while(i<=k)
        {
            int curr=0;
            int p = i;
            int s = k-i;
            p--;
            s = n-s;
            if(p>=0 and p<n) curr+=prefix[p];
            if(s>=0 and s<n) curr+=suffix[s];
            ans = max(ans,curr);
            i++;
        }
        return ans;
        
    }
};