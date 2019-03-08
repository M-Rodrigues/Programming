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

int adj[N][N], a, b, q, t, m;

int main() {
	while(scanf("%d",&m) != EOF) {
		t++;
		cl(adj, 63);

		for (int i = 0; i < m; i++) {
			scanf("%d",&a);
			adj[1][a] = adj[a][1] = 1;
		}

		for (int i = 2; i <= 19; i++) {
			scanf("%d",&m);
			for (int j = 0; j < m; j++) {
				scanf("%d",&a);
				adj[i][a] = adj[a][i] = 1;
			}
		}

		for (int k = 1; k <= 20; k++) 
			for (int i = 1; i <= 20; i++) 
				for (int j = 1; j <= 20; j++) 
					adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);

		scanf("%d",&q);
		printf("Test Set #%d\n",t);
		while(q--) {
			scanf("%d%d",&a,&b);
			printf("%2d to %2d: %d\n",a,b,adj[a][b]);
		}
		printf("\n");
	}
	return 0;
}
