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

ll dp[N][N], v[N], w[N];
ll pai[N], size[N];
ll peso[N], b[N];

int find(int x) { return (x == pai[x] ? x : pai[x] = find(pai[x])); }

void unite(int a, int b) {
	a = find(a);
	b = find(b);

	if (a == b) return;

	if (size[a] < size[b]) swap(a,b);
	pai[b] = a;
	size[a] += size[b];
}


int main() {
	int n, m, t;
	scanf("%d%d%d",&n,&m,&t);



	for(int i = 1; i <=  n; i++) scanf("%lld",&peso[i]);
	for(int i = 1; i <= n; i++) scanf("%lld",&b[i]);
	for(int i = 0; i < N; i++) pai[i]=i, size[i]=1;

	for(int i = 1; i <= n; i++) printf("%d -> (%lld, %lld) | ",i,pai[i],size[i]); printf("\n");

	while (m--) { // dsu
		int x, y;
		scanf("%d%d",&x,&y);

		if (find(x) != find(y))
			unite(x,y);
	}

	for(int i = 1; i <= n; i++) printf("%d -> (%lld, %lld) | ",i,pai[i],size[i]); printf("\n\n");


	for(int i = 1; i <= n; i++) printf("%d -> (%lld, %lld) | ",i,w[i], v[i]); printf("\n");
	
	for (int i = 1; i <= n; i++) w[pai[i]] += peso[i], v[pai[i]] += b[i];
	
	for(int i = 1; i <= n; i++) printf("%d -> (%lld, %lld) | ",i,w[i], v[i]); printf("\n");



	for (int i = 1; i <= n; i++) { // n = numero de grupos de amigas
		for (int j = 0; j <= t; j++) { // t = peso maximo q o anfi aguenta
			if (i == 1) dp[i][j] = (w[i] <= j ? v[i] : 0); // w[i] = peso do grupo i	v[i] = beleza do grupo i
			else {
				dp[i][j] = dp[i-1][j];
				if (w[i] <= j) {
					dp[i][j] = max(dp[i][j], v[i] + dp[i-1][j - w[i]]);
				}
			}
		}
	}

	printf("%lld\n",dp[n][t]);

	return 0;
}
