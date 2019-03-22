vector<vector<int> > Solution::prettyPrint(int A) {
    if (A == 1) {
        vector<vector<int>> ans(1);
        vector<int> l(1);
        l[0] = 1;
        ans[0] = l; return ans;
    }
    
    vector<vector<int>> m = Solution::prettyPrint(A-1);
    
    vector<vector<int>> ans;
    vector<int> l(2*A-1, A);
    
    ans.push_back(l);
    for (int i = 0; i < m.size(); i++) {
        ans[i+1].push_back(A);
        for (int j = 0; j < m[i].size(); j++) {
            ans[i+1].push_back(m[i][j]);
        }
        ans[i+1].push_back(A);
    }
    ans.push_back(l);
    
    return ans;
}
