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
const int N = 1e3+5;

int n, e, t, m, a, b, w, adj[N][N];

int main() {
	scanf("%d%d%d%d",&n,&e,&t,&m);
	cl(adj, 63);
	for (int i = 0; i < m; i++) {
		scanf("%d%d%d",&a,&b,&w);
		adj[a][b] = w;
	}
	for (int i = 1; i <= n; i++) adj[i][i] = 0;

	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);

	int count = 0;
	for (int i = 1; i <= n; i++)
		if (adj[i][e] <= t) count++;

	printf("%d\n",count);

	return 0;
}
