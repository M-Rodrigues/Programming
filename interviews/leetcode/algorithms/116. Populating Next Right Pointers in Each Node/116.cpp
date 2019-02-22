/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/

// BFS
class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr) return root;
        
        queue<pair<Node*, int>> q;
        q.push({root, 1});
        
        while (!q.empty()) {
            pair<Node*, int> elem = q.front(); q.pop();
            Node* cur = elem.first;
            int level = elem.second;
            
            if (!q.empty() and (q.front().second == level)) {
                cur->next = q.front().first;
            }
            
            if (cur->left != nullptr) {
                q.push({cur->left, level+1});
                q.push({cur->right, level+1});
            }
        }
        return root;
    }
};
