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

int n, ans, a, b, vis[N], max_d, min_d;
vi adj[N];
queue<pii> q;

int main() {
	int t = 0;
	while (scanf("%d",&n), n != 0) {
		t++;
		cl(vis, 0);
		for (int i = 0; i < N; i++) adj[i].clear();
		
		if (n == 1) ans = 1;
		else {
			for (int i = 0; i < n-1; i++) {
				scanf("%d%d",&a,&b);
				adj[a].pb(b);
				adj[b].pb(a);
			}

			min_d = INF;
			for (int i = 1; i <= n; i++) {
				cl(vis, 0);
				max_d = 0;

				vis[i] = 1;
				q.push({i, 0});

				while (!q.empty()) {
					pii P = q.front(); q.pop();
					int v = P.st;
					int d = P.nd;
					
					max_d = max(max_d,d);
					
					for (int u : adj[v]) if (!vis[u]) {
						vis[u] = 1; q.push({u, d+1});
					}
				}

				if (max_d < min_d) {
					min_d = max_d;
					ans = i;
				}
			}
		}

		printf("Teste %d\n",t);
		printf("%d\n\n",ans);
	}
	return 0;
}
