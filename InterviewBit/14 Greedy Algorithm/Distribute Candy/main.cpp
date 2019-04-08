int Solution::candy(vector<int> &A) {
    vector<int> c(A.size(),1);

    // left -> right
    for (int i = 0; i < A.size(); i++) {
        if (i > 0 and A[i] > A[i-1]) 
            c[i] = max(c[i], c[i-1]+1);
        if (i < A.size()-1 and A[i] > A[i+1]) 
            c[i] = max(c[i], c[i+1]+1);
    }
    
    // left <- right
    for (int i = A.size()-1; i >= 0; i--) {
        if (i > 0 and A[i] > A[i-1]) 
            c[i] = max(c[i], c[i-1]+1);
        if (i < A.size()-1 and A[i] > A[i+1]) 
            c[i] = max(c[i], c[i+1]+1);
    }
    
    // counting all candies
    int ans = 0;
    for (int x : c) ans += x;
    
    return ans;
}
