/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool ancestor(TreeNode*root,TreeNode*p,vector<TreeNode*>&v)
    {
        if(root==NULL) return false;
        v.push_back(root);
        if(root->val == p->val) return true;
        if(ancestor(root->left,p,v)==true or ancestor(root->right,p,v)==true) return true;
        v.pop_back();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
       vector<TreeNode*> v1,v2;
       
        int i=0;
        int j = 0;
       
        if( ancestor(root,p,v1)==false or    ancestor(root,q,v2)==false) return NULL;
        //  for(auto x:v1) cout<<x->val<<" ";
        // cout<<"\n";
        //   for(auto x:v2) cout<<x->val<<" ";
        // cout<<"\n";
        while(i<v1.size()-1 and j<v2.size()-1)
        {
            if(v1[i+1] != v2[j+1]) return v1[i];
            i++;
            j++;
            
        }
        if(i<v1.size()-1) return v1[i];
        if(j<v2.size()-1) return v2[j];
        return NULL;
    }
};