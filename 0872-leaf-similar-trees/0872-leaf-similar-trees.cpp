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
     vector<int> v1;
        vector<int> v2;
    void traverse(TreeNode*root)
    {
        if(root!=NULL)
        {
            if(root->left==NULL and root->right==NULL) v1.push_back(root->val);
            traverse(root->left);
            traverse(root->right);
        }
    }
     void traverse1(TreeNode*root)
    {
        if(root!=NULL)
        {
            if(root->left==NULL and root->right==NULL) v2.push_back(root->val);
            traverse1(root->left);
            traverse1(root->right);
        }
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
      traverse(root1);
        traverse1(root2);
        for(auto x:v1) cout<<x<<" ";
        cout<<"\n";
          for(auto x:v2) cout<<x<<" ";
        return (v1==v2);
    }
};