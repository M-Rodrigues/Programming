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
const int N = 2e3+5;

int memo[N][N];
string s1, s2;

int edist(int n, int m) {
	if (~memo[n][m]) return memo[n][m];
	if (n == 0 or m == 0) return memo[n][m] = max(n,m);
	if (s1[n-1] == s2[m-1]) return memo[n][m] = edist(n-1,m-1);
	
	int d1 = edist(n-1,m);
	int d2 = edist(n-1,m-1);
	int d3 = edist(n,m-1);

	return memo[n][m] = 1 + min({d1,d2,d3});
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		cl(memo, -1);
		
		cin >> s1 >> s2;

		printf("%d\n",edist(s1.size(),s2.size()));
	}
	return 0;
}
