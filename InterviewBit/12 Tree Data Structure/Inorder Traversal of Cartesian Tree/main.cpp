int maxVal(const vector<int> &A, int l, int r) {
    int val = INT_MIN, id = l;
    for (int i = l; i <= r; i++)
        if (A[i] > val)
            val = A[i], id = i;
    return id;
}

TreeNode* build(const vector<int> &A, int l, int r) {
    if (l > r) return NULL;
    
    int id = maxVal(A,l,r);
    
    TreeNode* node = new TreeNode(A[id]);

    node->left = build(A,l,id-1);
    node->right = build(A,id+1,r);

    return node;
} 

TreeNode* Solution::buildTree(vector<int> &A) {
    return build(A,0,(int)A.size()-1);
}
