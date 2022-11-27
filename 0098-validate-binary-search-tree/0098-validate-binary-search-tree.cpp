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
    bool func(TreeNode*root,long long  min,long long max){
        if(root==NULL) return true;
        return (root->val>min and root->val<max and func(root->left,min,root->val) and func(root->right,root->val,max));
    }
    bool isValidBST(TreeNode* root) {

        return func(root,LONG_MIN,LONG_MAX);
    }
};