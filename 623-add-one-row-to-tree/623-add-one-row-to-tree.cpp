class Solution {
    
    int value = 0 ; 
 
public:
    void func(TreeNode* root , int depth)
    {
        if(!root)
            return ; 
        if(depth == 2)
        {
                TreeNode* new_left =  new TreeNode(value) ; 
                new_left->left = root->left; 
                root->left = new_left; 
                TreeNode* new_right =  new TreeNode(value) ; 
                new_right->right = root->right; 
                root->right = new_right; 
        }
        
        func(root->left, depth-1) ;
        func(root->right,depth-1) ;
        return ; 
    
    }
    
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        value = val ; 
        if(depth == 1)
        {
            TreeNode* new_node = new TreeNode(val) ;
            new_node->left = root; 
            root = new_node;
            return root; 
        }
        func(root, depth);
        return root; 
        
    }
};