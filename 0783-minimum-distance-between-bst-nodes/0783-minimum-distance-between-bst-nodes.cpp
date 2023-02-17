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
   int ans= INT_MAX;
    vector<int> v;
    void Traverse(TreeNode* root){
        if(root!=NULL) {
            Traverse(root->left);
            v.push_back(root->val);
            Traverse(root->right);
        }
    }
    int minDiffInBST(TreeNode* root) {
       Traverse(root);
        for(int i=1;i<v.size();i++){
            ans = min(ans,v[i]-v[i-1]);
        }
        return ans;
    }
};