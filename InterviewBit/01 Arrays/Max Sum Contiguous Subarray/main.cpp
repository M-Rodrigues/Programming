int Solution::maxSubArray(const vector<int> &A) {
    int sum = 0, cur = 0;
    
    for (int i = 0; i < A.size(); i++) {
        if (i == 0) {
            sum = cur = A[i]; 
        } else {
            if (cur + A[i] < A[i]) {
                cur = A[i];
            } else {
                cur += A[i];
            }
            if (cur > sum) sum = cur;
        }
    }
    
    return sum;
}
