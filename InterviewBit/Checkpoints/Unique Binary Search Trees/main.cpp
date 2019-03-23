/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

vector<TreeNode*> dp(int i, int j, vector<vector<vector<TreeNode*>>> &memo) {
    if (i > j) return memo[i][j];
    if (i == j) {
        if (memo[i][j].size() == 0) {
            TreeNode *node = new TreeNode(i);
            memo[i][j].push_back(node);
        }
        return memo[i][j];
    }
    
    if (memo[i][j].size() == 0) {
        /* root = raiz da arvore */
        for (int root = i; root <= j; root++) {
            vector<TreeNode*> lt = dp(i,root-1,memo);
            vector<TreeNode*> rt = dp(root+1,j,memo);
            
            vector<TreeNode*> aux(1,nullptr);
            if (lt.size() == 0) lt = aux;
            if (rt.size() == 0) rt = aux;
            
            for (TreeNode* l : lt) {
                for (TreeNode* r : rt) {
                    TreeNode *tree = new TreeNode(root);
                    tree->left = l;
                    tree->right = r;
                    
                    memo[i][j].push_back(tree);
                }
            }
        }
    }
    
    return memo[i][j];
}


vector<TreeNode*> Solution::generateTrees(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    vector<vector<vector<TreeNode*>>> memo(A+2,vector<vector<TreeNode*>>(A+2,vector<TreeNode*>({})));
    
    return dp(1,A,memo);
}
