int search(int l, int r, int n) {
    if (n <= 1) return n;
    if (l == r) return l*l <= n ? l : l-1;
    
    int mid = (l+r)/2;
    
    if (mid == n/mid) return mid;
    
    if (mid < n/mid) return search(mid+1,r,n);
    return search(l,mid,n);
}

int Solution::sqrt(int A) {
    int x = search(1,A/2,A);
    
    if (x == 46341) {
        if ((x-1)*(x-1) < A) return x-1;
    }
    return x*x > A ? x-1 : x;
}
