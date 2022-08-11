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
    bool dfs(TreeNode* root, long long mn, long long mx) {
        if(!root) return true;
        
        if(root->val <= mn || root->val >= mx) return false;
        
        bool left = dfs(root->left, mn, root->val);
        bool right = dfs(root->right, root->val, mx);
        
        return left && right;
    }
    
public:
    bool isValidBST(TreeNode* root) {
        return dfs(root, LONG_MIN, LONG_MAX);
    }
};