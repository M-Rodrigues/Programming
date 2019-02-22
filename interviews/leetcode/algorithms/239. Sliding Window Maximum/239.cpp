#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans; A = nums;
        st.assign(nums.size()+1, -1);

        build(1, 0, nums.size()-1);

        for (int i = 0; i <= nums.size()-k; i++)
            ans.push_back(nums[query(1, 0, nums.size()-1, i, i+k)]);

        return ans;
    }
private:
    vector<int> st;
    vector<int> A;

    void build(int p, int L, int R) {
        if (L == R) {
            st[p] == L; return;
        }

        int mid = (L+R)/2;
        build(2*p, L, mid);
        build(2*p+1, mid+1, R);

        int l = st[2*p], r = st[2*p+1];

        st[p] = (A[l] <= A[r]) ? l : r;
    }

    int query(int p, int L, int R, int i, int j) {
        if (i > R or j < L) return -1;
        if (L >= i and R <= j) return st[p];

        int mid = (L+R)/2;
        int l = query(2*p, L, mid, i, j);
        int r = query(2*p+1, mid+1, R, i, j);

        if (l == -1) return r;
        if (r == -1) return l;
        return (A[l] <= A[r]) ? l : r;
    }
};

int main() {
    Solution q;

    vector<int> input({1,3,-1,-3,5,3,6,7});
    vector<int> output(q.maxSlidingWindow(input, 3));

    for (int x : output) printf("%d ",x);
    printf("\n");

    return 0;
}