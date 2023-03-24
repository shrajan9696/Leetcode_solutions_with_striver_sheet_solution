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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
     
        // simple level order traversal
        
        vector<vector<int>> res;
        if(root==NULL) return res;
        queue<TreeNode*> q;
        q.push(root);
        int flag=0;
        while(!q.empty()){
            
            int count = q.size();
            vector<int> ans;
            for(int i=0;i<count;i++){
                auto u = q.front();
               if(u!=NULL) ans.push_back(u->val);
                q.pop();
                if(u->left!=NULL) q.push(u->left);
                if(u->right!=NULL) q.push(u->right);
            }
            if(flag==1) reverse(ans.begin(),ans.end());
            res.push_back(ans);
            if(flag==1) flag=0;
            else flag=1;
        }
        return res;
    }
};