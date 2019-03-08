#include<bits/stdc++.h>
using namespace std;

int solve(int n) {
	int dp[n+1];

	if (n == 1) return 1;
	if (n == 2) return 2;
	if (n == 3) return 4;

	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;

	for (int i = 4; i <= n; i++) dp[i] = dp[i-1]+dp[i-2]+dp[i-3];

	return dp[n];
}

int main() {
	cout << solve(5) << endl;
	return 0;
}
