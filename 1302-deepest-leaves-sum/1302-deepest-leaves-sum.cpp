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
    int lvl = 0;
    int sum = 0;
    void getSum(TreeNode* root,int curlvl){
  
        if(!root)return ;
        
        if(lvl == curlvl){
            sum += root->val;   
        }
        if(curlvl>lvl){
            
            sum = root->val;
            lvl = curlvl;
        }
        
     getSum(root->left,curlvl+1);
    
     getSum(root->right,curlvl+1);
    
    
    }
    
    
    
    int deepestLeavesSum(TreeNode* root) {
        
        getSum(root,1);
        
        return sum;
    }
};