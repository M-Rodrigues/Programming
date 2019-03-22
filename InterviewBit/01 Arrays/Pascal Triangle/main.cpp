vector<vector<int> > Solution::solve(int A) {
    vector<vector<int>> ans;
    
    for(int i = 0; i < A; i++) {
        vector<int> l;
        
        for (int j = 0; j <= i; j++) {
            if (j == 0) l.push_back(1);
            else if (j == i) l.push_back(1);
            else l.push_back(ans[i-1][j]+ans[i-1][j-1]);
        }
        
        ans.push_back(l);
    }
    
    return ans;
}