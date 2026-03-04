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
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        vector<int> v;
        if(root==NULL) return v;
        s.push(root);
        while(!s.empty()){
            TreeNode* x=s.top();
            s.pop();

            v.push_back(x->val);
            if(x->right)
                s.push(x->right);
            if(x->left)
                s.push(x->left);
        }
        return v;
    }
};