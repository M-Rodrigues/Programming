int Solution::solve(vector<int> &A, vector<int> &B, vector<int> &C) {
   int a, b, c, ans = INT_MAX;
   
   a = A.size()-1, b = B.size()-1, c = C.size()-1;
   
   int dif = abs(max({A[a],B[b],C[c]})-min({A[a],B[b],C[c]}));
   while (dif <= ans) {
       int e = max({A[a],B[b],C[c]});
       ans = min(ans, dif);
       
       if (A[a] == e) {
           if (a == 0) break;
           else a--;
       } else if (B[b] == e) {
           if (b == 0) break;
           else b--;
       } else {
           if (c == 0) break;
           else c--;
       }
       
       dif = max({A[a],B[b],C[c]})-min({A[a],B[b],C[c]});
   }
    
    return ans;
}
