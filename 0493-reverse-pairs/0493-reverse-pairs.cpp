
 #include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
  using namespace __gnu_pbds; 
typedef tree<long long int, null_type, less_equal<long long int>,
             rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_set;

  class Solution {
     public:

    int reversePairs(vector<int>& nums) {
        int ans=0;
        ordered_set s;
        int n = nums.size();
        for(int i=n-1;i>=0;i--){
          
          
                ans+=(s.order_of_key(nums[i]));
               s.insert(2*1ll*nums[i]);
          
            
        }
        return ans;
    }
};