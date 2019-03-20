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
  int maxPathSum(TreeNode* root) {
    pair<int,int> ans = build(root);
    return max({ans.first, ans.second});
  }
private:
  pair<int,int> build(TreeNode *node) {
    if (node->left == nullptr and node->right == nullptr) {
      return {node->val, node->val};
    }
    
    pair<int,int> L = (node->left != nullptr) ? build(node->left) : make_pair(0,0) ;
    pair<int,int> R = (node->right != nullptr) ? build(node->right) : make_pair(0,0) ;
    pair<int,int> ans;
    
    /* DPS */
    ans.first = node->val;
    if (node->left != nullptr) 
      ans.first = max(ans.first, node->val + L.first);
    
    if (node->right != nullptr) 
      ans.first = max(ans.first, node->val + R.first);
    
    /* EPS */
    ans.second = ans.first;
    if (node->left != nullptr) 
      ans.second = max(ans.second, L.second);
    
    if (node->right != nullptr) 
      ans.second = max(ans.second, R.second);

    ans.second = max(ans.second, node->val + L.first + R.first);
    
    return ans;
  }
};