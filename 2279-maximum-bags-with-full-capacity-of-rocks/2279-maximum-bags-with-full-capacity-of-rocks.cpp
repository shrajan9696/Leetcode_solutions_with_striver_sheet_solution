class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        vector<int> diff;
        for(int i=0;i<capacity.size();i++)
        {
            diff.push_back(capacity[i] - rocks[i]);
        }
        sort(diff.begin(),diff.end());
        int ans=0;
        for(int i=0;i<diff.size();i++)
        {
            if(additionalRocks>=diff[i]){
                ans++;
            additionalRocks-=diff[i];
            }
        }
        return ans;
    }
};