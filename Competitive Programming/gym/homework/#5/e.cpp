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

int n, m, vis[N], a, b, col[N];
bool ok;
vi adj[N];


void dfs(int x) {
	if (vis[x]) return;
	vis[x] = 1;

	for (int v : adj[x]) {
		if (col[v] == -1) col[v] = 1^col[x];
		else if (col[v] == col[x]) ok = false;
		dfs(v);
	}
}

int main() {
	int t = 0;
	while(scanf("%d%d",&n,&m) != EOF) {
		t++;
		ok = true;
		cl(vis, 0);
		cl(col, -1);
		for (int i = 0; i < N; i++) adj[i].clear();

		for (int i = 0; i < m; i++) {
			scanf("%d%d",&a,&b);
			adj[a].pb(b);
			adj[b].pb(a);
		}

		col[1] = 0;
		dfs(1);
		printf("Instancia %d\n",t);
		printf("%s\n\n", ok ? "sim" : "nao");
	}
	return 0;
}
