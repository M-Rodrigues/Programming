/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


void unite(TreeNode *l, TreeNode *node) {
    TreeNode *aux = l;
    while (aux->right != nullptr) aux = aux->right;
    aux->right = node;
}

TreeNode* Solution::flatten(TreeNode* A) {
    if (A == nullptr) return nullptr;
    TreeNode *aux = A->right;
    A->right = flatten(A->left);
    A->left = nullptr;
    unite(A, flatten(aux));
    return A;
}


