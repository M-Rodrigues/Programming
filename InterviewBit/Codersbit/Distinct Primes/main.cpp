void sieve(vector<int> &primes) {
    for (int i = 2; i < primes.size(); i++) {
        if (primes[i] == 1) {
            primes[i] = i;
            for (int j = 2*i; j < primes.size(); j+=i)
                primes[j] = i;
        }
    }
}

void countFactors(int n, unordered_set<int> &ans, vector<int> &primes) {
    while (n > 1) {
        ans.insert(primes[n]);
        n /= primes[n];
    }   
}

int maxVal(vector<int> &A) {
    int ans = A[0];
    for (int x : A) ans = max(ans, x);
    return ans;
}

int Solution::solve(vector<int> &A) {
    if (A.size() == 0) return 0;
    
    int N = maxVal(A);
    vector<int> primes(N+1,1);
    unordered_set<int> ans;
    
    sieve(primes);
    // for (int i = 2; i < primes.size(); i++) printf("%d -> %d\n",i,primes[i]);
    
    for (int x : A)
        countFactors(x,ans,primes);
    
    return (int)ans.size();
}
