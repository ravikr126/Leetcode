class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        vector<int> path;
        dfs(root, targetSum, 0, path, res);
        return res;
    }

    void dfs(TreeNode* node, int targetSum, int curSum,
             vector<int>& path, vector<vector<int>>& res) {
        if (!node) return;

        curSum += node->val;
        path.push_back(node->val);

        if (!node->left && !node->right && curSum == targetSum) {
            res.push_back(path);
        }

        dfs(node->left, targetSum, curSum, path, res);
        dfs(node->right, targetSum, curSum, path, res);

        path.pop_back();
    }
};