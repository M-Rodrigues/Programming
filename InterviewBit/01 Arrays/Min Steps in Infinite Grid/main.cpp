int Solution::coverPoints(vector<int> &A, vector<int> &B) {
    int movs = 0, N = A.size();
    for (int i = 1; i < N; i++) {
        int x0 = A[i-1], y0 = B[i-1];
        int x1 = A[i], y1 = B[i];
        
        int a = abs(x1-x0);
        int b = abs(y1-y0);
        
        movs += min(a,b) + abs(a-b);
    }
    
    return movs;
}