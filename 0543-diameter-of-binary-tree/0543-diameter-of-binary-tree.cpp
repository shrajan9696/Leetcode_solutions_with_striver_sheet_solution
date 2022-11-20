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
    int res=0;
    int height(TreeNode*root)
    {
        if(root==NULL) return 0;
        else return 1+max(height(root->left),height(root->right));
    }
    void traversal(TreeNode*root)
    {
        if(root!=NULL)
        {
              res=max((height(root->left)+height(root->right)),res);
              traversal(root->left);
              traversal(root->right);
        }
    }
    int diameterOfBinaryTree(TreeNode* root) {
       
        traversal(root);
        return res;
    }
};