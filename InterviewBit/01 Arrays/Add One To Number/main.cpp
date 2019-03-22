vector<int> Solution::plusOne(vector<int> &A) {
    int id = 0;
    for (int i = 0; i < A.size(); i++) {
        id = i;
        if (A[i] != 0) {
            break;
        }
    }
    
    if (id == A.size()) {
        A.clear();
        A.push_back(1);
        return A;
    }
    
    int N = A.size()-id;
    
    for (int i = id; i < A.size(); i++) {
        A[i-id] = A[i];
    }
    
    A.resize(N);
    
    int c = 1;
    for (int i = A.size()-1; i >= 0; i--) {
        c += A[i];
        A[i] = c%10;
        
        c /= 10;
        
        if (c == 0) break;
    }
    
    if (c == 1) {
        A.push_back(0);
        for (int i = A.size()-1; i > 0; i--) {
            A[i] = A[i-1];
        }
        A[0] = 1;
    }
    
    return A;
}



