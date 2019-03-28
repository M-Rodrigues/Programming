bool emptyRow(int i, vector<string> &m) {
    for (char x : m[i]) if (x != '.') return false;
    return true;
}

bool isValidPosition(int ii, int jj, vector<string> &m) {
    int n = (int)m.size();
    for (int i = 0; i < n; i++) if (i != ii and m[i][jj] == 'Q') return false;
    for (int j = 0; j < n; j++) if (j != jj and m[ii][j] == 'Q') return false;
    
    for (int k = 1; ii+k < n and jj+k < n; k++) if (m[ii+k][jj+k] == 'Q') return false;
    for (int k = 1; ii+k < n and jj-k >= 0; k++) if (m[ii+k][jj-k] == 'Q') return false;
    for (int k = 1; ii-k >= 0 and jj+k < n; k++) if (m[ii-k][jj+k] == 'Q') return false;
    for (int k = 1; ii-k >= 0 and jj-k >= 0; k++) if (m[ii-k][jj-k] == 'Q') return false;
    
    return true;
}

void bt(int i, int j, vector<string> &m, vector<vector<string>> &ans) {
    /* extrapolou o limite interior -> configuração válida */
    if (i == m.size()) { 
        vector<string> aux = m;
        ans.push_back(aux);
        return; 
    }
    
    /* extrapolou o limite lateral */
    if (j == m.size()) { 
        if (!emptyRow(i,m)) bt(i+1,0,m,ans); 
        return; 
    }
    
    if (!isValidPosition(i,j,m)) { bt(i,j+1,m,ans); return;}
    
    m[i][j] = 'Q';
    bt(i+1,0,m,ans);
    m[i][j] = '.';
    bt(i,j+1,m,ans);
}

vector<vector<string> > Solution::solveNQueens(int A) {
    string s = "";
    for (int i = 0; i < A; i++) s.push_back('.');
    
    vector<vector<string>> ans;
    vector<string> m(A,s);
    
    bt(0,0,m,ans);
    return ans;
}
