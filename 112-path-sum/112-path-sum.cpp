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
    bool fun(TreeNode *node, int req){
        if(!node) return false;
        int x = req - node -> val;
        if(node -> left == NULL && node -> right == NULL){
            return (x == 0);
        }
        return fun(node -> left, x) || fun(node -> right, x);
        
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return fun(root, targetSum);
    }
};





//2nd sol

// class Solution {
// public:
//     bool hasPathSum(TreeNode* root, int targetSum) {
//        if(!root)
//             return false;
//         if(!root->left && !root->right && targetSum - root->val == 0)
//             return true;
//         return (hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val));
//     }
// };