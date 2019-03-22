int fat(int n) {
    if (n == 0) return 1;
    return n*fat(n-1);
}

string build(int n, int k, int fn, vector<int> &rem) {
    if (n == 1) return to_string(rem[0]);
    
    /* first upper bound */
    int up = fn-1;
    
    /* searching for block position */
    while (up < k) up += fn;
    
    /* number to append */
    int app = up/fn;
    string aux = to_string(rem[app]);
    rem.erase(rem.begin() + app);
    
    /* move to next position */
    return aux + build(n-1,k - up + fn -1, fn/(n-1), rem);
}

string Solution::getPermutation(int A, int B) {
    string ans = "";
    vector<int> rem;
    for (int i = 1; i <= A; i++) rem.push_back(i);
    
    return build(A, B-1, fat(A-1), rem);    
}