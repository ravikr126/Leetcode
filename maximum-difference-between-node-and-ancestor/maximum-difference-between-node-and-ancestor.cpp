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
      void solve(TreeNode* root, int low, int high, int &result){
        if(root==NULL)
            return;
        low=min(low,root->val);
        high=max(high,root->val);
        result=max(result,high-low);
        
        solve(root->left,low,high,result);
        solve(root->right,low,high,result);
    }
    int maxAncestorDiff(TreeNode* root) {
        if(root==NULL)
            return 0;
        int low=root->val;
        int high=root->val;
        
        int result=high-low;
        solve(root,low,high,result);
        return result;
    }
};