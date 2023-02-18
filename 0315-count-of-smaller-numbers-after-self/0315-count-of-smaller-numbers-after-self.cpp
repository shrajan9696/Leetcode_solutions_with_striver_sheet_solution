
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
  using namespace __gnu_pbds; 
typedef tree<int, null_type, less_equal<int>,
             rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_set;

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        ordered_set s;
        int n = nums.size();
        s.insert(nums[n-1]);
        vector<int> v;
        v.push_back(0);
        for(int i=n-2;i>=0;i--){
            s.insert(nums[i]);
            v.push_back( s.order_of_key(nums[i]));
            
        }
        reverse(v.begin(),v.end());
        return v;
        
    }
};