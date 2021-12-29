/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
           //base case
    if(root == NULL) return NULL;
    //connects the left subtree of same level with right subtree of that same level 
    if(root->left != NULL) root->left->next = root->right;
    //connect the rightmost node of a level to the leftmost node of the next level.
    if(root->right != NULL && root->next != NULL) root->right->next = root->next->left;
    //recursive calls for left and right subtrees.
    connect(root->left);
    connect(root->right);
    return root;
    }
};