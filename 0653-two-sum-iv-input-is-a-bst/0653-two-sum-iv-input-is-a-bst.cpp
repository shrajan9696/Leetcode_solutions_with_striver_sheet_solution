/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool func(TreeNode*root,set<int> &st,int sum)
    {
        if(root==NULL) return false;
        if(func(root->left,st,sum)==true)
        {
            return true;
        }
        if(st.find(sum-root->val)!=st.end()){
            return true;
        }
        else{
            st.insert(root->val);
            return func(root->right,st,sum);
        }
        return false;
    }
    bool findTarget(TreeNode* root, int k) {
      set<int> s;
        // for(auto x:s) cout<<x<<" ";
        return func(root,s,k);
    }
};