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
    vector<int> v;
    map<int,int> m;
    void post(TreeNode*root)
    {
        if(root!=NULL)
        {
            v.push_back(root->val);
            post(root->left);
            post(root->right);
        }
    }
    bool findTarget(TreeNode* root, int k) 
    {
      post(root);
      for(int i=0;i<v.size();i++)
      {
          if(m[k-v[i]]>0) return true;
          m[v[i]]++;
      }  
        return false;
        
    }
};