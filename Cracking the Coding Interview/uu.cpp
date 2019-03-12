#include<bits/stdc++.h>
using namespace std;

int LowerBound(int start, int end, const vector<int> &A, int B) { // Binary Search (Lower Bound)
    if (start == end) return A[start] == B ? start : -1;
    
    int mid = (start+end)/2;

    if (A[mid] >= B) return LowerBound(start,mid,A,B);
    return LowerBound(mid+1, end, A, B);
}

int UpperBound(int start, int end, const vector<int> &A, int B) { // Binary Search (Upper Bound)
    if (start == end) return A[start] == B ? start : -1;
    
    int mid = (start+end+1)/2;

    if (A[mid] <= B) return UpperBound(mid,end,A,B);
    return UpperBound(start, mid-1, A, B);
}