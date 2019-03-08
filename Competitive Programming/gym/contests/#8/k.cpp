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
const int N = 2e3+5;

vi adj[N];
int cap[N], n, m, k, vis[N], tam;

void dfs(int x) {
	if (vis[x]) return;
	vis[x] = 1;
	tam++;
	for (int v : adj[x])
		dfs(v);
}
	
void dfs2(int x) {
	if (vis[x]) return;
	vis[x] = 1;
	for (int v : adj[x])
		tam++, dfs2(v);
}

void pA() {
	for (int i = 1; i <= n; i++) printf("%d ",vis[i]); printf("\n");
}

int main() {

	scanf("%d%d%d",&n,&m,&k);

	for (int i = 0; i < k; i++) scanf("%d",&cap[i]);

	while (m--) {
		int a, b;
		scanf("%d%d",&a,&b);
		adj[a].pb(b);
		adj[b].pb(a);
	}

	ll mx = 0;
	for (int i = 0; i < k; i++) {
		tam = 0;
		dfs(cap[i]);
		if (tam > mx) mx = tam;
	}

	// pA();

	int noCon = 0;
	for (int i = 1; i <= n; i++) if (!vis[i]) noCon++;


	tam = 0;
	for (int i = 1; i <= n; i++) if (!vis[i]) {dfs2(i);}

	// printf("vertices na maior componente: %lld\n",mx);
	// printf("vertices fora de alguma capi: %d\n",noCon);
	// printf("arestas fora de alguma capi: %d\n",tam);
	ll ans = noCon*mx + noCon*(noCon-1)/2;

	printf("%lld\n",ans);
	return 0;
}
