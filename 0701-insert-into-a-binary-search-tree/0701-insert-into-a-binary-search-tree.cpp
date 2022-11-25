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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode*res = root;
       TreeNode*curr = root;
       TreeNode*temp = new TreeNode(val);
        if(root==NULL) return temp;
        else{
            while(root!=NULL)
            {
                curr= root;
                if(root->val > val) root=root->left;
                else if(root->val < val) root = root->right;
            }
            if(curr->val > val) curr->left = temp;
            else curr->right = temp;
        }
        return res;
    }
};