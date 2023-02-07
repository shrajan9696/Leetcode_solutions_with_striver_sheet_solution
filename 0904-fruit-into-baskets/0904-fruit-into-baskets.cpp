class Solution {
public:
    int totalFruit(vector<int>& fruits) {
     int start=0;
        int end=0;
        int n = fruits.size();
        int ans=0;
        map<int,int> m;
        while(start<n and end<n)
        {
            m[fruits[end]]++;
            if(m.size() <= 2)
            {
                ans = max(ans,(end-start+1));
            }
            else if(m.size()>2)
            {
                m[fruits[start]]--;
                if(m[fruits[start]]<=0) m.erase(fruits[start]);
                start++;
            }
            end++;
        }
        return ans;
    }
};