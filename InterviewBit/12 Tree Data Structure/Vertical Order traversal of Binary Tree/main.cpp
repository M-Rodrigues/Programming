vector<vector<int> > Solution::verticalOrderTraversal(TreeNode* A) {
    if (A == NULL) return {};
    
    vector<vector<int>> ans(1);
    queue<pair<TreeNode*,int>> q;
    int l = 0, r = 0;
    
    q.push({A, 0});
    while (!q.empty()) {
        int x = q.front().second;
        TreeNode *n = q.front().first;
        q.pop();
        
        if (x >= l and x <= r) {
            ans[x-l].push_back(n->val);
        } else {
            vector<int> ll(1,n->val);
        
            if (x < l) {
                l = x;
                ans.insert(ans.begin(),ll);
            }
            if (x > r) {
                r = x;
                ans.push_back(ll);
            }
        }
        
        if (n->left != NULL) q.push({n->left, x-1});
        if (n->right != NULL) q.push({n->right, x+1});
    }
    
    return ans;
}
