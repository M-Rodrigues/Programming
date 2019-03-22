void build(vector<int>& cur, vector<vector<int>> &ans, vector<int>&A) {
    if (A.size() == 0) {
        ans.push_back(cur);
        return;
    }
    
    for (int i = 0; i < A.size(); i++) {
        cur.push_back(A[i]);
        A.erase(A.begin()+i);
        
        build(cur, ans, A);
        
        int x = cur[cur.size()-1];
        cur.pop_back();
        A.push_back(x);
    }
}

vector<vector<int> > Solution::permute(vector<int> &A) {
    vector<vector<int>> ans;
    vector<int> cur;
    
    
    sort(A.begin(), A.end());
    
    build(cur, ans, A);
    
    return ans;
}
