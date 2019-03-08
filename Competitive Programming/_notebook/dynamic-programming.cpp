#include<bits/stdc++.h>
typedef long long ll;

// LCS - Longest Common Subsequence - O(n*m) //

int memo[N][N], a[N], b[N];
cl(memo, -1);
int lcs(int n, int m) {
    if (~memo[n][m]) return memo[n][m];
    if (n == -1 or m == -1) return memo[n][m] = 0;
    if (a[n-1] == b[m-1]) return memo[n][m] = 1 + lcs(n-1,m-1);
    else return memo[n][m] = max(lcs(n-1,m), lcs(n,m-1));
}
//  Bottom-Up
for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
        if (i == 0 or j == 0) memo[i][j] = 0;
        else if (a[i-1] == b[j-1]) memo[i][j] = 1 + memo[i-1][j-1];
        else memo[i][j] = max(memo[i-1][j], memo[i][j-1]);
    }
}


// LIS - Longest Increasing Subsequence - O(n*log(n))

int l[N], a[N];

int lis(int n) {
    int j = 0;
    for (int i = 0; i < n; i++) {
        int pos = lower_bound(l, l+j, a[i]) - l;
        l[pos] = a[j]; j = max(j, pos+1);
    }
    return j;
}

// Knapsack - O(n*t)

int sack[N][M]; // n = number of elements, t = capacity of the knapsack
int w[N], v[N]; // weight and value, respectively.

for(int i=0; i<n; i++) {
    for(int j=0; j<=t; j++) {
        if(i == 0) dp[i][j] = (w[i] <= j ? v[i] : 0);
        else {
            dp[i][t] = dp[i-1][j];
            if(w[i] <= j) {
                dp[i][j] = max(dp[i][j], v[i] + dp[i-1][j-w[i]]);
            }
        }
    }
}