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

int e, l, comp[101];
vi adjList[101];

void showAdjList() {
	for (int i = 1; i <= e; i++){
		printf("%d -> ",i);
		for (int j = 0; j < adjList[i].size(); j++) printf("%d ",adjList[i][j]);
		printf("\n");
	}
}

void dfs(int x) {
	if (comp[x] == -1) {
		comp[x] = 0;
		for (int i = 0; i < adjList[x].size(); i++) dfs(adjList[x][i]);
	}
}

bool isConex() {
	for (int i = 1; i <= e; i++) {
		for (int k = 1; k <= e; k++) comp[k] = -1;
		dfs(i);
		
		for (int k = 1; k <= e; k++) if (comp[k] == -1) return false;
	}
	return true;
}

int main() {
	int t = 1;
	while (scanf("%d%d",&e,&l), e+l != 0) {
		for (int i = 1; i <= l; i++) {
			int a, b;
			scanf("%d%d",&a,&b);
			adjList[a].pb(b);
			adjList[b].pb(a);
		}

		// showAdjList();

		printf("Teste %d\n",t);
		printf("%s\n\n",(isConex() ? "normal" : "falha"));

		// Liberação de memória
		for (int i = 1; i <= e; i++) adjList[i].clear();
		t++;
	}
	return 0;
}
