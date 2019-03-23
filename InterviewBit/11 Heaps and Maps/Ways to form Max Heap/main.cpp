int MOD = 1000000007;
vector<vector<int>> bin;

void build() {
    for (int i = 0; i < bin.size(); i++) {
        bin[i][0] = bin[i][i] = 1;
    }
    
    for (int n = 1; n < bin.size(); n++) {
        for (int k = 1; k < n; k++) {
            bin[n][k] = (bin[n-1][k] + bin[n-1][k-1])%MOD;
        }
    }
}

long long int H(int n) {
    if (n == 0) return 1;
    if (n == 1) return 1;
    
    int h = log(n)/log(2);
    int m = 1 << h;
    int p = n - m + 1;
    int L = m-1;
    
    if (p < m/2) L -= m/2 - p;
    
    return ((bin[n-1][L]%MOD * H(L)%MOD)%MOD * H(n-L-1)%MOD)%MOD;
}

int Solution::solve(int A) {
    bin.assign(A+1, vector<int>(A+1));
    build();
    return H(A);
}
