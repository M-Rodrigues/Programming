#include<bits/stdc++.h>
using namespace std;

class SegmentTree {
    vector<int> st;
    vector<int> A;
public:
    SegmentTree(vector<int>& arr) {
        A = arr; 
        int N = (int)arr.size();
        st.assign(4*N, 0);

        build(1, 0, N-1);
    }

    int query(int i, int j) {
        return *query(1, 0, A.size()-1, i, j);
    }
private:
    void build(int p, int L, int R) {
        if (L == R) {
            st[p] = L;
        } else {
            int l = 2*p, r = 2*p+1;
            int mid = (L+R)/2;

            build(l, L, mid);
            build(r, mid+1, R);

            st[p] = (A[st[l]] <= A[st[r]]) ? st[l] : st[r];
        }
    }

    int* query(int p, int L, int R, int i, int j) {
        if (i <= L and R <= j) return &st[p];
        if (i > R or j < L) return nullptr;

        int mid = (L+R)/2, l = 2*p, r=2*p+1;
        int* i1 = query(l, L, mid, i, j);
        int* i2 = query(r, mid+1, R, i, j);

        if (i1 == nullptr) return i2;
        if (i2 == nullptr) return i1;

        return (A[*i1] <= A[*i2]) ? i1 : i2;
    }
};

int main() {
    vector<int> input({1,3,-1,-3,5,3,6,7});
    SegmentTree st(input);
    
    cout << st.query(1,1) << endl;
    cout << st.query(2,2) << endl;
    cout << st.query(3,3) << endl;
    cout << st.query(4,4) << endl;
    cout << st.query(5,5) << endl;
    cout << st.query(6,6) << endl;
    cout << st.query(7,7) << endl;
    cout << st.query(8,8) << endl;

    return 0;
}