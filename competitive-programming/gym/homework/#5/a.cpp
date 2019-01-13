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

int n, t, aux;
vector<int> portal, vis;

bool dfs(int x) {
	if (vis[x] != -1) return false;
	else {
		if (portal[x] > n) return false;
		//printf("Estou no nó %d (t = %d)\n",portal[x],t);
		vis[x] = 0;
		if (portal[x] == t) return true;
		dfs(portal[x]);
	}
}

int main() {
	scanf("%d%d",&n,&t);

	portal.pb(0);
	vis.pb(0);

	for (int i = 1; i < n; i++){
		scanf("%d",&aux);
		portal.pb(aux + i);
		vis.pb(-1);
	}

	// for (int i = 1; i < n; i++) printf("%d -> %d\n",i,portal[i]);

	printf("%s\n",dfs(1) ? "YES" : "NO");


	return 0;
}
