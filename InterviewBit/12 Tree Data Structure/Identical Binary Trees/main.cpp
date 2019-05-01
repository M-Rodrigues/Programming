/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::isSameTree(TreeNode* A, TreeNode* B) {
    if (A == nullptr and B == nullptr) return true;
    if (A == nullptr and B != nullptr) return false;
    if (A != nullptr and B == nullptr) return false;
    
    if (A->val != B->val) return false;
    return isSameTree(A->left, B->left) && isSameTree(A->right, B->right);
}
