int commonIndex(vector<string> &A) {
    int k = -1;
    
    while (true) {
        for (int i = 1; i < A.size(); i++) {
            if (A[i].size() <= k+1) return k;
            if (A[i][k+1] != A[i-1][k+1]) return k;
        }
        k++;
    }
}

string Solution::longestCommonPrefix(vector<string> &A) {
    if (A.size() == 0) return "";
    if (A.size() == 1) return A[0];
    
    int index = commonIndex(A);
    return A[0].substr(0,index+1);    
}
