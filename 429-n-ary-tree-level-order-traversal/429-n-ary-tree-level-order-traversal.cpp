/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
          vector<vector<int>> result;

    if (!root) {
        return result;
    }
      
    queue <Node *> q;
    q.push(root);

    while(!q.empty()) {
        int size = q.size();
        vector<int> levelNodes;

        while(size--) {      
            levelNodes.push_back(q.front()->val);
            
            for (int j = 0; j != q.front()->children.size(); j++) {
                q.push(q.front()->children[j]);
            }
            
            q.pop();
        }
        
        result.push_back(levelNodes);
    }
      
    return result;  
    }
};