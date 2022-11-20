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
    unordered_map<TreeNode*,int>m;
    int res=0;
    int height(TreeNode*root)
    {
        if(root==NULL) return 0;
        else {
        
             return m[root]=   1+max(height(root->left),height(root->right));
          
            
        }
       
    }
    void traversal(TreeNode*root)
    {
        
        if(root!=NULL)
        {
              // res=max((height(root->left)+height(root->right)),res);
            res=max(res,(m[root->left]+m[root->right]));
              traversal(root->left);
              traversal(root->right);
        }
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int x = height(root);
        traversal(root);
        for(pair<TreeNode*,int>p:m) {
            if(p.first!=NULL){
            cout<<p.first->val<<" "<<p.second<<" ";
        }
        }
        return res;
    }
};