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
    bool func(TreeNode*r1,TreeNode*r2){
        if(r1==NULL and r2==NULL) return true;
        if(r1!=NULL and r2==NULL) return false;
        if(r1==NULL and r2!=NULL) return false;
       return (r1->val == r2->val and func(r1->left,r2->right) and func(r1->right,r2->left));
    }
    bool isSymmetric(TreeNode* root) {
         TreeNode* r1;
    TreeNode* r2;
        r1 = root;
        r2 = root;
        return func(r1,r2);
    }
};