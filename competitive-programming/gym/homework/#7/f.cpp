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
const int N = 1e3;

ll a, b, w, n, m, adj[N][N], in, fim;

int main() {
	while (scanf("%lld%lld",&n,&m) and n+m != 0) {
		cl(adj, 63);
		for (int i = 1; i <= n; i++) adj[i][i] = 0;

		for (int i = 0; i < m; i++) {
			scanf("%lld%lld%lld",&a,&b,&w);
			adj[a][b] = w;
		}

		scanf("%lld%lld",&in,&fim);

		for (int k = 1; k <= n; k++)
			for (int i = 1; i <= n; i++)
				for (int j = 1; j <= n; j++)
					adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);

		// dist[in] = 0;
		// pq.push(mp(0,in));

		// while (!pq.empty()) {
		// 	int u = pq.top().nd;
		// 	ll d = -pq.top().st;
		// 	pq.pop();

		// 	if (d > dist[u]) continue;

		// 	for (int i = 0; i < adj[u].size(); i++) {
		// 		int v = adj[u][i];
		// 		ll w = d + adjw[u][i];

		// 		if (w < dist[v]) {
		// 			dist[v] = w;
		// 			pq.push(mp(-w,v));
		// 		}
		// 	}
		// }
		
		printf("%lld\n", (adj[in][fim] == LINF) ? -1 : adj[in][fim]);
	}
	return 0;
}
