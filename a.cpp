#include<bits/stdc++.h>
using namespace std;

int search(int l, int r, int n) {
    int mid = (l+r)/2;
    int n1 = mid*mid;
    int n2 = (mid+1)*(mid+1);
    
    cout << mid << endl;

    if (n1 == n) return mid;
    if (n2 > n and n1 < n) return mid;
    
    if (n1 < n) return search(mid+1,r,n);
    return search(l,mid-1,n);
}

int sqrt(int A) {
    if (A == (1 << 31)-1) return search(0,A/2,A); 
    return search(0,A,A);
}

int main() {
    int n = (1 << 31)-1;

    cout << sqrt(n) << endl;


    return 0;
}