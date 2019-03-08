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

int n,  pai[N], sz[N];
double x, y, minPath;
vector<pair<double,double>> cidades;
vector<pair<double,pii>> edges;

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
	while (scanf("%d",&n) and n) {
		minPath = 0;
		cidades.clear();
		edges.clear();

		for (int i = 0; i < n; i++) {
			scanf("%lf%lf",&x,&y);
			cidades.pb(mp(x,y));

			for (int j = i - 1; j >= 0; j--) {
				double w = sqrt((x-cidades[j].st)*(x-cidades[j].st) + (y-cidades[j].nd)*(y-cidades[j].nd));
				edges.pb(mp(w,mp(j,i)));
			}
		}
		
		sort(edges.begin(), edges.end());

		for (int i = 0; i < N; i++) pai[i] = i, sz[i] = 1;

		for (pair<double,pii> e : edges) {
			int u = e.nd.st;
			int v = e.nd.nd;
			double w = e.st;

			if (find(u) != find(v)) {
				unite(u,v);
				minPath = max(minPath,w);
			}
		}
		

		printf("%.4lf\n",minPath);
	}
	return 0;
}
