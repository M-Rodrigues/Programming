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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        preOrder(root, ans);
        return ans;
    }
private:
    void preOrder(TreeNode* node, vector<int> &ans) {
        if (node == nullptr) return;
        
        ans.push_back(node->val);
        preOrder(node->left, ans);
        preOrder(node->right, ans);
    }
};