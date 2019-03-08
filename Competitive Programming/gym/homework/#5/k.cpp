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

int n, m, a, b, inc[N];
vi ts;
// set<int> adj[N];
vi adj[N];
queue<int> q;

int main() {
	while (scanf("%d%d",&n,&m), n+m != 0) {
		cl(inc, 0);
		for (int i = 0; i < N; i++) adj[i].clear();
		ts.clear();		
		
		for (int i = 0; i < m; i++) {
			scanf("%d%d",&a,&b);
			
			// if (adj[a].count(b) == 0) {
			// 	adj[a].insert(b);
			// 	inc[b]++;
			// }
			adj[a].pb(b);
			inc[b]++;
		}

		// for (int i = 1; i <= n; i++) {
		// 	printf("%d -> ",i);
		// 	for (int v : adj[i]) printf("(%d: %d) ",v,inc[v]);
		// 	printf("\n");
		// }
		// for (int i = 1; i <= n; i++) printf("(%d: %d)%c",i,inc[i],(i==n?'\n':' '));
		for (int i = 1; i <= n; i++) if (inc[i] == 0) q.push(i);
		
		while (!q.empty()) {
			int u = q.front(); q.pop();
			for (int v : adj[u])
				if (inc[v] > 0 and --inc[v] == 0) 
					q.push(v);
			ts.pb(u);
			//for (int i = 1; i <= n; i++) printf("(%d: %d)%c",i,inc[i],(i==n?'\n':' '));
		}

		for (int i = 0; i < ts.size(); i++) printf("%d%c",ts[i],(i+1==n?'\n':' '));
	}
	return 0;
}
