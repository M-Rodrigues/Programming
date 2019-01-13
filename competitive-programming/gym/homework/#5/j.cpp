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

int grid[N][N], n, m, inicio, ans, vis[N];
vi adj[N];
queue<pii> q;

int main() {
	scanf("%d%d",&n,&m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int pos = i*m+j;
			scanf("%d",&grid[i][j]);

			if (grid[i][j] == 3) inicio = pos;

			if (i == 0) {
				if (j > 0) {
					if (grid[i][j] != 2 and grid[i][j-1] != 2)
						adj[pos].pb(pos-1), adj[pos-1].pb(pos);
				}
			} else if (j == 0) {
				if (i > 0) {
					if (grid[i][j] != 2 and grid[i-1][j] != 2)
						adj[pos].pb(pos-m), adj[pos-m].pb(pos);
				}
			} else {
				if (grid[i][j] != 2) {
					if(grid[i-1][j] != 2)
						adj[pos].pb(pos-m), adj[pos-m].pb(pos);
					if(grid[i][j-1] != 2)
						adj[pos].pb(pos-1), adj[pos-1].pb(pos);
				} 
			}
		}
	}

	// for (int i = 0; i < n*m; i++) {
	// 	printf("%d -> ",i);
	// 	for (int v : adj[i]) printf("%d ",v);
	// 	printf("\n");
	// }

	vis[inicio] = 1;
	q.push({inicio, 0});
	
	while (!q.empty()) {
		pii P = q.front(); q.pop();
		int v = P.st;
		int d = P.nd;

		int i = v/m;
		int j = v%m;

		if (grid[i][j] == 0 and ans == 0) ans = d;

		for (int u : adj[v]) if (!vis[u]) {
			vis[u] = 1; q.push({u, d+1});
		}
	}

	printf("%d\n",ans);

	return 0;
}
