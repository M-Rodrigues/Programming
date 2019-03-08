#include<bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define cl(x, v) memset((x), (v), sizeof(x))
#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<
#define gcd(x, y) __gcd((x), (y))

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vi> vii;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f, LMOD = 1011112131415161719ll;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 5e3+5;

ll dp[N][N];

int main() {
	int n;
	scanf("%d",&n);
	string s;

	for (int i = 0; i < n; i++) scanf("%c",&s[i]);

	dp[0][0] = 1;
	for (int i = 1; i <= n-1; i++) {
		if (s[i-1] == 'f')
			for (int j = 1; j <= i-1; j++) dp[i+1][j] = dp[i][j-1];
		else {
			ll ps = 0;
			for (int j = i-1; i >= 0; i--) {
				ps = (ps + dp[i-1][j])%MOD;
				dp[i][j] = ps;
			}
		}
	}

	ll sum = 0;
	for (int j = 0; j <= n-1; j++)
		sum = (sum + dp[n-1][j])%MOD;

	printf("%lld\n",sum);
	return 0;
}
