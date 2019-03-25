/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
TreeNode* buildBST(int L, int R, vector<int> &arr) {
    if (L > R) return nullptr;
    
    if (L == R) return new TreeNode(arr[L]);
    
    int mid = L + (R-L)/2;
    TreeNode *root = new TreeNode(arr[mid]);
    
    root->left = buildBST(L,mid-1,arr);
    root->right = buildBST(mid+1,R,arr);
    
    return root;
} 
 
TreeNode* Solution::sortedListToBST(ListNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    vector<int> arr;
    
    ListNode *cur = A;
    while (cur != nullptr) {
        arr.push_back(cur->val);
        ListNode *aux = cur;
        cur = cur->next;
        delete aux;
    }
    
    return buildBST(0,(int)arr.size()-1,arr);
}
