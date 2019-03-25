int Solution::longestSubsequenceLength(const vector<int> &A) {
    int N = (int)A.size();
    if (N == 0) return 0;
    
    vector<int> lisd(N), lisr(N);
    
    /* normal lis */
    for (int i = 0; i < N; i++) {
        lisd[i] = 1;
        for (int k = 0; k < i; k++) {
            if (A[k] < A[i])
                lisd[i] = max(lisd[i], lisd[k] + 1);
        }
    }
    
    /* reversed lis */
    for (int i = N-1; i >= 0; i--) {
        lisr[i] = 1;
        for (int k = N-1; k > i; k--) {
            if (A[i] > A[k])
                lisr[i] = max(lisr[i], lisr[k] + 1);
        }
    }
    
    int ans = 0;
    for (int i = 0; i < N; i++)
        ans = max(ans, lisd[i]+lisr[i]-1);
        
    return ans;
}
