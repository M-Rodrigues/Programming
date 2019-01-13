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

int n, m, op, comp[2001];
vector<int> adjList[2001];

void showAdjList() {
	for (int i = 1; i <= n; i++){
		printf("%d -> ",i);
		for (int j = 0; j < adjList[i].size(); j++) printf("%d ",adjList[i][j]);
		printf("\n");
	}
}

void dfs(int x){
	if (comp[x] == -1) {
		comp[x] = 0;
		for(int i=0;i<adjList[x].size();i++){
			int v = adjList[x][i];
			dfs(v);
		}
	}
}

bool isConex() {
	for (int i = 1; i <= n; i++) {
		for (int k = 1; k <= n; k++) comp[k] = -1;
		dfs(i);
		for (int j = 1; j <= n; j++) if (comp[j] == -1) return false;
	}
	return true;
}

int main() {
	scanf("%d",&n);
	while (n != 0) {
		scanf("%d",&m);

		// Receber as ruas (Arestas)
		for (int i = 1; i <= m; i++) {
			int a, b;
			scanf("%d%d%d",&a,&b,&op);
			if (op == 1) { // Mao Unica: a -> b
				adjList[a].pb(b);
			} else { // Mao Dupla: a -> b e b -> a
				adjList[a].pb(b);
				adjList[b].pb(a);
			}
		}

		//showAdjList();

		printf("%d\n",(isConex() ? 1 : 0));

		// Liberar espaço de memória
		for (int i = 1; i <= n; i++) adjList[i].clear();

		// Novo caso
		scanf("%d",&n);
	}

	return 0;
}