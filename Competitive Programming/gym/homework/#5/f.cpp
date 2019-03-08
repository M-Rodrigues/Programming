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
const int N = 1e5+5;

int n, m, a, b, inicio, p, vis[N];
vi adj[N], ans;
queue<pii> q;

int main() {
	int t = 0;
	while (scanf("%d%d%d%d",&n,&m,&inicio,&p), n+m+inicio+p != 0){
		t++;
		cl(vis, 0);
		for (int i = 0; i < N; i++) adj[i].clear();
		ans.clear();

		while (m--) {
			scanf("%d%d",&a,&b);
			adj[a].pb(b);
			adj[b].pb(a);
		}

		vis[inicio] = 1;
		q.push({inicio, 0});

		while (!q.empty()) {
			pii P = q.front(); q.pop();
			int v = P.st;
			int d = P.nd;

			if (d > 0 and d <= p) ans.pb(v);

			for (int u : adj[v]) if (!vis[u]) {
				vis[u] = 1; q.push({u, d+1});
			}
		}

		sort(ans.begin(),ans.end());

		printf("Teste %d\n",t);
		for (int v : ans) printf("%d ",v);
		printf("\n\n");
	}
	return 0;
}