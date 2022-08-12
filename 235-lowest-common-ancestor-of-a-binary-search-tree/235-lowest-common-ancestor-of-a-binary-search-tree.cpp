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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
         int current = root->val;
        if(p->val < current && q->val < current) {
            return lowestCommonAncestor(root->left, p, q);
        }
        else if(p->val > current && q->val > current) {
            return lowestCommonAncestor(root->right, p, q);
        }
        else{
            return root;
        }
    }
};