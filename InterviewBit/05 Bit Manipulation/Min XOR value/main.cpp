int Solution::findMinXor(vector<int> &A) {
    int val;
    
    for (int i = 0; i < A.size(); i++) {
        for (int j = i+1; j < A.size(); j++) {
            if (i == 0 and j == 1) val = A[i] ^ A[j];
            else {
                int XOR = A[i] ^ A[j];
                if (XOR < val) val = XOR;
            }
        }
    }
    
    return val;
}
