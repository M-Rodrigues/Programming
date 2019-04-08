int Solution::maxProduct(const vector<int> &A) {
    int maxi, mini, ans;
    ans = maxi = mini = A[0];
    
    for (int i = 1; i < A.size(); i++) {
        int aux = maxi;
        maxi = max({A[i], A[i]*maxi, A[i]*mini});
        mini = min({A[i], A[i]*aux, A[i]*mini});
        
        ans = max({ans, maxi, mini});
    }
    
    return ans;
}
