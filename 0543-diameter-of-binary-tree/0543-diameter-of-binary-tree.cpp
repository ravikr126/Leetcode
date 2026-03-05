class Solution {
    int res = 0;

public:
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return res;        
    }

private:
    int dfs(TreeNode* root) {
        if (!root) {
            return 0;
        }

        int l = dfs(root->left);
        int r = dfs(root->right);

        res = std::max(res, l + r);

        return 1 + std::max(l, r);
    }    
};