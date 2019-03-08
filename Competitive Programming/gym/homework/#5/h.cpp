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

int n, m, vis[N], col[N], a, b;
vi adj[N];
bool ok;
queue<int> q;

// void dfs1(int x) {
// 	vis[x] = 1;
// 	for (int v : adj[x]) if (!vis[v]) dfs1(v);
// }

// void dfs2(int x) {
// 	if (vis[x]) return;
// 	vis[x] = 1;

// 	for (int v : adj[x]) {
// 		if (col[v] == -1) col[v] = 1^col[x];
// 		else if (col[v] == col[x]) ok = false;
// 		dfs2(v);
// 	}
// }

// bool isConex() {
// 	for (int i = 1; i <= n; i++) {
// 		cl(vis, 0); dfs1(i);
// 		for (int j = 1; j <= n; j++) if (vis[j] == 0) return false;
// 	}
// 	return true;
// }

// bool isCiclic() {
// 	cl(vis, 0);
// 	cl(col, -1);

// 	ok = true;
// 	col[1] = 0;
// 	dfs2(1);
// 	return !ok;
// }

int main() {
	scanf("%d%d",&n,&m);

	if (m != n-1) printf("NO\n");
	else {
		while (m--) {
			scanf("%d%d",&a,&b);
			adj[a].pb(b);
			adj[b].pb(a);
		}

		cl(vis, 0);
		cl(col, -1);

		q.push(1);
		vis[1] = 1;
		ok = true;
		while (!q.empty()) {
			int u = q.front(); q.pop();
			
			// db(u);
			// db(ok);
			// db(vis[u] _ u);
			for (int v : adj[u]) {
				if (!vis[v]) {
					vis[v] = 1;
					q.push(v);
				}
				if (col[v] == -1) col[v] = 1^col[u];
				else if (col[v] == col[u]) ok = false;
			}
		}

		for (int i = 1; i <= n; i++) if (vis[i] == 0) ok = false;

		printf("%s\n",ok?"YES":"NO");
	}
	return 0;
}
