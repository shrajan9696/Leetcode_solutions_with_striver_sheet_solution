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
    
    map<int,int> m;
     TreeNode* build(vector<int>inorder, vector<int>postorder,int is,int ie, int *postindex)
     {
         if(is>ie) return NULL;
         TreeNode*root = new TreeNode(postorder[*postindex]);
         (*postindex)--;
         int inindex = m[root->val];
         root->right = build(inorder,postorder,inindex+1,ie,postindex);
         root->left = build(inorder,postorder,is,inindex-1,postindex);
         return root;
         
     }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i=0;i<inorder.size();i++){
            m[inorder[i]] = i;
        }
        int postindex = postorder.size()-1;
        return build(inorder,postorder,0,inorder.size()-1,&postindex);
    }
};