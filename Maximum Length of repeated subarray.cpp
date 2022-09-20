class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int ans=0;
        for(int i= -n+1;i<m;i++){
            int count=0;
            for(int j=0;j<n;j++){
                if((i+j)<0){
                    continue;
                }
                else if((i+j)>=m){
                    break;
                }
                else if((nums2[i+j]==nums1[j])){
                    count++;
                    ans=max(count,ans);
                }
                else count=0;
                
            }
            // ans=max(count,ans);
        }
        return ans;
    }
};
