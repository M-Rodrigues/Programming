void build(int k, const vector<int> &A, vector<int> &cur, vector<vector<int>> &ans) {
    if (k == A.size()) return;
    
    /* current number in the subset */
    cur.push_back(A[k]);
    ans.push_back(cur);
    build(k+1,A,cur,ans);
    cur.pop_back();
    
    /* current value out of the subset */
    build(k+1,A,cur,ans);
}

vector<vector<int> > Solution::subsets(vector<int> &A) {
    vector<vector<int>> ans;
    vector<int> cur;
    
    sort(A.begin(), A.end());
    
    cur.clear(); ans.push_back(cur);
    build(0,A,cur,ans);
    return ans;
}
