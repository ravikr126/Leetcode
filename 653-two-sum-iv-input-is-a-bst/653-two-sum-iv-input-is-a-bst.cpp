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
    vector<int> v;
    
    void inorder(TreeNode *root)                 //Inorder == Sorted Array
    {             
        if(root==nullptr) return;
        inorder(root->left);
        v.push_back(root->val);
        inorder(root->right);
    }
    
    bool findTarget(TreeNode* root, int k) 
    {   
        inorder(root);
        
        if(v.size()==1) return false;            //Edge Case
        
        for(int i=0; i<v.size()-1; i++){
            int l=i+1, r=v.size()-1;
    
            while(l<=r){                       
                int mid=l+(r-l)/2;
                int sum=v[i]+v[mid];
                if(sum==k) return true;
                if(sum<k) l=mid+1;
                else if(sum>k) r=mid-1;
            }
        }
        return false;
    }
};