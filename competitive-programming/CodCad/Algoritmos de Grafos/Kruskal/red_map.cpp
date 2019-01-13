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

int n, m, pai[N], size[N], a, b, w;
vector<piii> edges;

int find(int x) {
	return (x == pai[x]) ? x : pai[x] = find(pai[x]);
}

void unite(int a, int b) {
	a = find(a);
	b = find(b);

	if (a == b) return;

	if (size[a] < size[b]) swap(a,b);
	size[a] += size[b];
	pai[b] = a;
}

int main() {
	scanf("%d%d",&n,&m);
	while (m--) {
		scanf("%d%d%d",&a,&b,&w);
		edges.pb(mp(w,mp(a,b)));
	}

	sort(edges.begin(), edges.end());

	for (int i = 0; i < N; i++) pai[i] = i, size[i] = 1;

	int cost = 0;
	for (piii e : edges) {
		int a = e.nd.st;
		int b = e.nd.nd;
		int w = e.st;
		
		if (find(a) != find(b))
			unite(a,b), cost += w;	
	}

	printf("%d\n",cost);

	return 0;
}
