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

vi adj[N], adjw[N]; //	adj[u] -> vizinhos de u onde (v,d), diz que existe ligação de u->v de peso d
int n, grid[105][105], dist[N];

int main() {
	scanf("%d",&n);
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d",&grid[i][j]);
			if (grid[i][j] == 1) grid[i][j] = 1000;
			int pos = i*n + j;

			if (i == 0) {
				if (j > 0) {
					adj[pos].pb(pos-1);
					adjw[pos].pb(grid[i][j]);
					
					adj[pos-1].pb(pos);
					adjw[pos-1].pb(grid[i][j-1]);
				}
			} else if (j == 0) {
				if (i > 0) {
					adj[pos].pb(pos-n);
					adjw[pos].pb(grid[i][j]);

					adj[pos-n].pb(pos);
					adjw[pos-n].pb(grid[i-1][j]);
				}
			} else {
				adj[pos].pb(pos-1);
				adjw[pos].pb(grid[i][j]);

				adj[pos-1].pb(pos);
				adjw[pos-1].pb(grid[i][j-1]);
					
				adj[pos].pb(pos-n);
				adjw[pos].pb(grid[i][j]);

				adj[pos-n].pb(pos);
				adjw[pos-n].pb(grid[i-1][j]);
			}

		}
	}

	// for (int i = 0; i < n*n; i++) {
	// 	printf("%d -> ", i);
	// 	for (int j = 0; j < adj[i].size(); j++) printf("(%d: %d) ",adj[i][j],adjw[i][j]);
	// 	printf("\n");
	// }

	cl(dist, 63);
	priority_queue<pii> pq;

	dist[0] = 0;
	pq.push(mp(0,0));

	while (!pq.empty()) {
		int u = pq.top().nd;
		int d = -pq.top().st;
		pq.pop();

		if (d > dist[u]) continue;

		for (int i = 0; i < adj[u].size(); i++) {
			int v = adj[u][i];
			int w = d + adjw[u][i];

			// printf("%d -> %d : w = %d : dist[%d] = %d\n",u,v,w,v,dist[v]);
			if (w < dist[v]) 
				dist[v] = w, pq.push(mp(-w,v));
		}
	}

	printf("%d\n",dist[n*n-1]/1000);


	return 0;
}