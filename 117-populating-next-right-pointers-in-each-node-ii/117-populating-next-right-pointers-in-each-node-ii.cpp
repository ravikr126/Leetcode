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
         queue<Node*> q;
        if(root) q.push(root);
        while(!q.empty()) {
            int qSize = q.size();
            Node* prev = nullptr;
            for(int i = 0; i < qSize; i++) {
                auto top = q.front();
                q.pop();
                top->next = prev;
                prev = top;
                if(top->right) q.push(top->right);
                if(top->left) q.push(top->left);
            }
        }
        
        return root;
    }
};