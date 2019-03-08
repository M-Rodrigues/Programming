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

int n, m, x, y, z, t, pai[N], sz[N];
vector<pii> mst;
vector<piii> edges;

int find(int x) {
	return (pai[x] == x) ? x : pai[x] = find(pai[x]);
}

void unite(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;
	
	if (sz[a] < sz[b]) swap(a,b);
	pai[b] = a;
	sz[a] += sz[b];
}

int main() {
	while(scanf("%d%d",&n,&m) and n and m) {
		mst.clear();
		edges.clear();

		for(int i = 0; i < m; i++) {
			scanf("%d%d%d",&x,&y,&z);
			edges.pb(mp(z,mp(x,y)));
		}
		sort(edges.begin(), edges.end());

		for (int i = 0; i < N; i++) pai[i] = i, sz[i] = 1;

		for (piii e : edges) {
			int u = e.nd.st;
			int v = e.nd.nd;

			if (find(u) != find(v)) {
				unite(u,v);
				if (v < u) swap(u,v);
				mst.pb(mp(u,v));
			}
		}
		sort(mst.begin(), mst.end());

		t++;
		printf("Teste %d\n",t);
		for (pii e : mst) 
			printf("%d %d\n",e.st,e.nd);
		printf("\n");
	}

	return 0;
}