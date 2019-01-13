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

int n, a, b, dist[N], vis[N], max_d, inicio;
vi adj[N];
queue<int> q;

int main() {
	scanf("%d",&n);

	for (int i = 0; i < n-1; i++) {
		scanf("%d%d",&a,&b);
		adj[a].pb(b);
		adj[b].pb(a);
	}


	// BFS em 1;
	q.push(1);
	dist[1] = 0;
	vis[1] = 1;

	while(!q.empty()) {
		int u = q.front(); q.pop();

		for (int v : adj[u]) if(!vis[v]) {
			q.push(v); vis[v] = 1;
			dist[v] = dist[u] + 1;
			if (dist[v] > max_d) max_d = dist[v], inicio = v;
		}
	}
	
	cl(vis, 0);

	// BFS no mais longe do 1
	q.push(inicio);
	vis[inicio] = 1;
	dist[inicio] = 0;
	max_d = 0;

	while(!q.empty()) {
		int u = q.front(); q.pop();

		for (int v : adj[u]) if(!vis[v]) {
			q.push(v); vis[v] = 1;
			dist[v] = dist[u] + 1;
			if (dist[v] > max_d) max_d = dist[v];
		}
	}
	
	printf("%d\n",max_d);

	return 0;
}
