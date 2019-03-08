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

int n, m, a, b, c, w, dist[N], vis[N];
vi adj[N], adjw[N];
priority_queue<pii> pq;

int main() {
	scanf("%d",&c);
	while(c--) {
		for (int i = 0; i < N; i++) adj[i].clear(), adjw[i].clear();

		scanf("%d%d",&n,&m);
		for (int i = 0; i < m; i++){
			scanf("%d%d%d",&a,&b,&w);
			adj[a].pb(b);
			adjw[a].pb(w);
		}

		bool ok = false;
		for (int x = 0; x < n; x++) {
			
			cl(dist, 63);
			cl(vis, 0);
			
			pq.push(mp(0,x));

			while(!pq.empty()) {
				int u = pq.top().nd;
				int d = -pq.top().st;
				pq.pop();

				if (d > dist[u]) continue;
				if (vis[u]) continue;

				vis[u] = 1;

				for (int i = 0; i < adj[u].size(); i++) {
					int v = adj[u][i];
					int w = d + adjw[u][i];

					if (w < dist[v]) {
						dist[v] = w;
						pq.push(mp(-w,v));
					}
				}
			}
			
			if (dist[x] < 0) ok = true;
		}

		printf("%s\n", ok ? "possible" : "not possible");

	}

	return 0;
}
