int Solution::uniquePaths(int A, int B) {
    A--; B--;
    int n = A+B;
    int m = min(A,B);
    
    if (m == 0) return 1;
    
    int ans = n;
    for (int i = m-1; i > 0; i--) {
        ans *= (n-i);
        ans /= (m-i);
    }
    
    return ans;
}