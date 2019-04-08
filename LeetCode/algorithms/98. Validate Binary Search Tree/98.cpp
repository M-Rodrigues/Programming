/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
  bool isValidBST(TreeNode* root) {
    vector<int> v;
    inOrder(root,v);
    
    for (int i = 1; i < v.size(); i++)
      if (v[i] <= v[i-1]) return false;
    return true;
  }
private:
  void inOrder(TreeNode *node, vector<int> &A) {
    if (node == nullptr) return;
    
    inOrder(node->left,A);
    A.push_back(node->val);
    inOrder(node->right, A);
  }
};