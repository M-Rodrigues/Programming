/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

void build(TreeNode *node, int level, vector<vector<int>> &A) {
    if (node == nullptr) return;
    
    if (level == A.size()) A.push_back(vector<int>());
    A[level].push_back(node->val);
    
    build(node->left, level+1, A);
    build(node->right, level+1, A);
}

void reverse(vector<vector<int>> &A) {
    for (int i = 1; i < A.size(); i+=2) {
        for (int j = 0; j < A[i].size()/2; j++) {
            int aux = A[i][j];
            A[i][j] = A[i][A[i].size()-j-1];
            A[i][A[i].size()-j-1] = aux;
        }
    }
}

vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* A) {
    vector<vector<int>> level;
    build(A, 0, level);
    reverse(level);
    return level;
}
