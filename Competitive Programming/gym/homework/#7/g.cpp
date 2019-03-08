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

int n, m, c, k, a, b, w, dist[N];
vi adj[N], adjw[N];

priority_queue<pii> pq;

int main() {
	while(scanf("%d%d%d%d",&n,&m,&c,&k) and n+m+c+k != 0) {
		// db(n _ m _ c _ k);
		for (int i = 0; i < N; i++) adj[i].clear(), adjw[i].clear();
		for (int i = 0; i < m; i++) {
			scanf("%d%d%d",&a,&b,&w);
			if (a > b) swap(a,b);

			if (b < c and a + 1 == b) {
				adj[a].pb(b);
				adjw[a].pb(w);
			} else if (a < c and b >= c) {
				adj[b].pb(a);
				adjw[b].pb(w);
				if (a == c-1) {
					adj[a].pb(b);
					adjw[a].pb(w);
				}
			} else if (a >= c and b < c) {
				adj[a].pb(b);
				adjw[a].pb(w);
			} else if (a < c and b < c){
				adj[b].pb(a);
				adjw[b].pb(w);
			} else {
				adj[a].pb(b);
				adj[b].pb(a);

				adjw[a].pb(w);
				adjw[b].pb(w);
			}
		}

		cl(dist, 63);

		pq.push(mp(0,k));

		while(!pq.empty()) {
			int u = pq.top().nd;
			int d = -pq.top().st;
			pq.pop();

			if (d > dist[u]) continue;
			
			for (int i = 0; i < adj[u].size(); i++) {
				int v = adj[u][i];
				int w = d+ adjw[u][i];
				if (w < dist[v]) {
					dist[v] = w;
					pq.push(mp(-w,v));
				}
			}
		}
		printf("%d\n",dist[c-1]);
	}
	return 0;
}
