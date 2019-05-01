/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* build(const vector<int> &A, int L, int R) {
    if (L > R) return nullptr;
    
    int mid = (L + R) / 2;
    TreeNode *root = new TreeNode(A[mid]);
    
    root->left = build(A, L, mid-1);
    root->right = build(A, mid+1, R);
    return root;
}

TreeNode* Solution::sortedArrayToBST(const vector<int> &A) {
    return build(A, 0, A.size()-1);
}
