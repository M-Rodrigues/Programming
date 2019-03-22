int solve(int i, int j, string &A, string &B, vector<vector<int>> &memo) {
    if (i == 0) return memo[i][j] = j;
    if (j == 0) return memo[i][j] = i;
    
    printf("%d %d -> %d\n",i,j,memo[i][j]);
    
    if (memo[i][j] != -1) return memo[i][j];
    
    int cost = (A[i-1] == B[j-1]) ? 0 : 1;
    return memo[i][j] = min({
        solve(i-1,j,A,B,memo)+1,
        solve(i,j-1,A,B,memo)+1,
        solve(i-1,j-1,A,B,memo)+cost
    });
}

int Solution::minDistance(string A, string B) {
    int N = A.size();
    int M = B.size();
    
    vector<vector<int>> memo(N+1, vector<int>(M+1));
    for (auto r : memo)
        for (int i = 0; i < r.size(); i++)
            r[i] = -1;
    memo[0][0] = 0;
    
    return solve(N,M,A,B,memo);
}
