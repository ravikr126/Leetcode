class Solution {
public:
    int ans = INT_MIN;

    int helper(TreeNode* node) {
        if (!node) return 0;
        int left = max(helper(node->left), 0);
        int right = max(helper(node->right), 0);
        ans = max(ans, node->val + left + right);
        return node->val + max(left, right);
    }

    int maxPathSum(TreeNode* root) {
        helper(root);
        return ans;
    }
};