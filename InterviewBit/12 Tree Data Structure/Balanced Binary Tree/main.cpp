/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

bool check(TreeNode *root, int* height)  { 
    if(root == NULL) {  
        *height = 0;  
        return true;  
    }  
    int lh = 0, rh = 0;  
    int l = 0, r = 0;  
  
    l = check(root->left, &lh);  
    r = check(root->right, &rh);  
    
    *height = max(lh,rh) + 1;  

    if(abs(lh-rh) >=2 )
        return false;  
    else 
        return l and r;  
}

int Solution::isBalanced(TreeNode* A) {
    int aux;
    return check(A, &aux);
}
