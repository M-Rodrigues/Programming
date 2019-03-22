bool rowVal(int ii, int val, vector<vector<char>> &t) {
    for (int j = 0; j < 9; j++) if (t[ii][j] == '0'+val) return false;
    return true;
}

bool colVal(int jj, int val, vector<vector<char>> &t) {
    for (int i = 0; i < 9; i++) if (t[i][jj] == '0'+val) return false;
    return true;
}

bool squareVal(int ii, int jj, int val, vector<vector<char>> &t) {
    ii /= 3; jj /= 3;
    
    for (int i = ii*3; i - ii*3 < 3; i++) {
        for (int j = jj*3; j - jj*3 < 3; j++) {
            if (t[i][j] == '0'+val) return false;
        }
    }
    return true;
}

void bt(int i, int j, vector<vector<char>> &t, vector<vector<char>> &A, bool *sol) {
    if (*sol) return;
    
    /* finish board -> got a solution */
    if (i == 9 and j == 0) { *sol = true; return; }
    
    /* escape from right border -> move to next line*/
    if (j == 9) { bt(i+1,0,t,A,sol); return; }
    
    /* if fixed number -> next cell */
    if (A[i][j] != '.') { bt(i,j+1,t,A,sol); return; }
    
    for (int k = 1; k <= 9; k++) {
        if (rowVal(i,k,t) and colVal(j,k,t) and squareVal(i,j,k,t)) {
            if (!(*sol)) {
                t[i][j] = '0'+k;
                bt(i,j+1,t,A,sol);
            }
            
            if (!(*sol)) {
                t[i][j] = '.';
            }
        }
    }
}

void Solution::solveSudoku(vector<vector<char> > &A) {
    /* build board with variable values */
    vector<vector<char>> m = A;
    bool sol = false;
    /* backtrack the solution */
    bt(0,0,A,m,&sol);
}
