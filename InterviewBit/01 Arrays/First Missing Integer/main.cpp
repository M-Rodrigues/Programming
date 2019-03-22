int Solution::firstMissingPositive(vector<int> &A) {
    sort(A.begin(), A.end());
    int val = 1;
    
    for (int x : A)
        if (x == val) val++;
    
    return val;
}
