void Solution::arrange(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int n = (int)A.size();
    for (int i = 0; i < n; i++) {
        if (A[A[i]] >= n) { // new value
            A[i] += (A[A[i]] % n)*n;
        } else { // old value
            A[i] += A[A[i]]*n;
        }
    }
    
    for (int i = 0; i < n; i++) {
        A[i] /= n;
    }
}
