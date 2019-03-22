int LowerBound(int start, int end, const vector<int> &A, int B) {
    if (start == end) return A[start] == B ? start : -1;
    
    int mid = (start+end)/2;

    if (A[mid] >= B) return LowerBound(start,mid,A,B);
    return LowerBound(mid+1, end, A, B);
}

int UpperBound(int start, int end, const vector<int> &A, int B) {
    if (start == end) return A[start] == B ? start : -1;
    
    int mid = (start+end+1)/2;

    if (A[mid] <= B) return UpperBound(mid,end,A,B);
    return UpperBound(start, mid-1, A, B);
}

vector<int> Solution::searchRange(const vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<int> ans(2);

    ans[0] = LowerBound(0, A.size()-1, A, B);
    
    // cout << ans[0] << endl;
    
    ans[1] = UpperBound(0, A.size()-1, A, B);
    
    return ans;
}
