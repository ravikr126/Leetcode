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
class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        inOrder(root);
    }
    
    int next() {
        curr++;
        return nodes[curr-1];
    }
    
    bool hasNext() {
        return curr != nodes.size();
    }
    
private:
    void inOrder(TreeNode* root) {
        if (!root)
            return;
        inOrder(root->left);
        nodes.push_back(root->val);
        inOrder(root->right);
    }
    
    vector<int> nodes;
    int curr = 0;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */